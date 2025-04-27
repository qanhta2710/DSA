#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *makeQueue();
Node *makeNode(int x);
bool isEmpty(Queue *head);
void enqueue(Queue *head, int x);
int dequeue(Queue *head);
int peek(Queue *head);
void display(Queue *head);
void freeQueue(Queue *q);

int main() {
    Queue *myQueue = makeQueue();
    int choice, x;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data you want to insert: ");
            scanf("%d", &x);
            enqueue(myQueue, x);
            break;
        case 2:
            x = dequeue(myQueue);
            if (x != -1) {
                printf("Deleted %d\n", x);
            } else {
                printf("UNDERFLOW");
            }
            break;
        case 3:
            x = peek(myQueue);
            if (x != -1) {
                printf("%d", peek(myQueue));
            } else {
                printf("UNDERFLOW");
            }
            break;
        case 4:
            display(myQueue);
            break;
        case 5:
            freeQueue(myQueue);
            printf("Exiting...");
            break;
        }
    } while (choice != 5);
}

Node *makeNode(int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

Queue *makeQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->rear = NULL;
    newQueue->front = NULL;
    return newQueue;
}

bool isEmpty(Queue *head) {
    if (head->front == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue *head, int x) {
    Node *newNode = makeNode(x);
    if (isEmpty(head)) {
        head->front = newNode;
        head->rear = newNode;
    } else {
        head->rear->next = newNode;
        head->rear = newNode;
    }
}

int dequeue(Queue *head) {
    if (isEmpty(head)) {
        return -1;
    }
    Node *tmp = head->front;
    int data = head->front->data;
    head->front = head->front->next;
    free(tmp);
    return data;
    
}

int peek(Queue *head) {
    if (isEmpty(head)) {
        return -1;
    } else {
        return head->front->data;
    }
}

void display(Queue *head) {
    Node *current = head->front;
    if (isEmpty(head)) {
        printf("NOT INITIALIZING...");
    } else {
        while (current != head->rear) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("%d", current->data);
    }
}

void freeQueue(Queue *q) {
    Node *current = q->front;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(q);        
}