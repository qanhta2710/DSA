#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    struct Node *left;
    char data;
    struct Node *right;
} Node;

typedef struct StackNode {
    Node *treeNode;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

Node *makeNode(char data);

Stack *makeStack();
void push(Stack *s, Node *treeNode);
Node *pop(Stack *s);
void freeStack(Stack *s);

Node *buildMathExpression(char input[]);
bool isOperatorOrOperand(char c);
bool isClosedBracket(char c);
void freeTree(Node *root);

void inOrderTraversal(Node *root);

int main() {
    char input[MAX];
    fgets(input, MAX, stdin);
    Node *mathExpression = buildMathExpression(input);
    inOrderTraversal(mathExpression);
    freeTree(mathExpression);
    return 0;
}

Node *makeNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

Stack *makeStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
} 

void push(Stack *s, Node *treeNode) {
    StackNode *newStackNode = (StackNode *)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = s->top;
    s->top = newStackNode;
}

Node *pop(Stack *s) {
    if (s->top == NULL) return NULL;
    StackNode *tmp = s->top;
    Node *treeNode = tmp->treeNode;
    s->top = tmp->next;
    free(tmp);
    return treeNode;
}

void freeStack(Stack *s) {
    while (s->top != NULL) {
        StackNode *tmp = s->top;
        s->top = s->top->next;
        free(tmp);
    } 
    free(s);
}

bool isOperatorOrOperand(char c) {
    if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}

bool isClosedBracket(char c) {
    if (c == ')' || c == ']' || c == '}') {
        return true;
    } else {
        return false;
    }
}

Node *buildMathExpression(char input[]) {
    Stack *s = makeStack();
    for (int i = 0; i < strlen(input); i++) {
        if (isOperatorOrOperand(input[i])) {
            Node *tmp = makeNode(input[i]);
            push(s, tmp);
        }
        if (isClosedBracket(input[i])) {
            Node *r = pop(s);
            Node *o = pop(s);
            Node *l = pop(s);
            o->left = l;
            o->right = r;
            push(s, o);
        }
    }
    Node *r = pop(s);
    Node *o = pop(s);
    Node *l = pop(s);
    o->left = l;
    o->right = r;
    push(s, o);
    Node *res = pop(s);
    freeStack(s);
    return res;
}

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void inOrderTraversal(Node *root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        printf("( ");
    }
    inOrderTraversal(root->left);
    printf("%c ", root->data);
    inOrderTraversal(root->right);
    if (root->right != NULL) {
        printf(") ");
    }
}