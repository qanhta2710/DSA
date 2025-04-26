#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1000

typedef struct Node {
    struct Node *left;
    int data;
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

Node *buildMathExpression(char input[]);
bool isOperatorOrOperand(char c);
bool isClosedBracket(char c);

void inOrderTraversal(Node *root);

int main() {
    char input[MAX];
    fgets(input, MAX, stdin);
    Node *mathExpression = buildMathExpression(input);
    inOrderTraversal(mathExpression);
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
    
}

void inOrderTraversal(Node *root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}