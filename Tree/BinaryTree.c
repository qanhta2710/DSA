#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} Node;

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Node *makeNode(int data);
void addleftChild(Node *par, int data);
void addrightChild(Node *par, int data);
void preOrderTraversal(Node *root);
void inOrderTraversal(Node *root);
void postOrderTraversal(Node *root);
void BFS(Node *root);

Queue *makeQueue();
void enqueue(Queue *q, Node *treeNode);
Node *dequeue(Queue *q);
bool isEmpty(Queue *q);

int main() {
    Node *root = makeNode(1);
    addleftChild(root, 2);
    addrightChild(root, 3);
    addleftChild(root->left, 4);
    addrightChild(root->left, 5);
    addleftChild(root->right, 6);
    addrightChild(root->right, 7);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    BFS(root);
    return 0;
}

Node *makeNode(int data) {
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
} 

void addleftChild(Node *par, int data) {
    Node *newNode = makeNode(data);
    par->left = newNode;
}

void addrightChild(Node *par, int data) {
    Node *newNode = makeNode(data);
    par->right = newNode;
}

void inOrderTraversal(Node *root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

Queue *makeQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isEmpty(Queue *q) {
    if (q->front == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue *q, Node *treeNode) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *tmp = q->front;
    Node *treeNode = tmp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(tmp);
    return treeNode;
}

void BFS(Node *root) {
    Queue *q = makeQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *curr = dequeue(q);
        printf("%d ", curr->data);
        if (curr->left != NULL) {
            enqueue(q, curr->left);
        }

        if (curr->right != NULL) {
            enqueue(q, curr->right);
        }
    }
    free(q);
}