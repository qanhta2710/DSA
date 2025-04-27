#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Node *makeNode(int data, int priority);
Queue *makeQueue();
bool isEmpty(Queue *head);
Queue *enqueue(Queue *head, int data, int priority);
int dequeue(Queue *head);
int peek(Queue *head);
void display(Queue *head);
void freeQueue(Queue *q);

int main() {
    Queue *myQueue = makeQueue();
    int choice, x, priority;
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
            printf("Enter the process priority: ");
            scanf("%d", &priority);
            enqueue(myQueue, x, priority);
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
                printf("%d", x);
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
    return 0;
}

Node *makeNode(int data, int priority) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

Queue *makeQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

bool isEmpty(Queue *head) {
    if (head->front == NULL) {
        return true;
    } else {
        return false;
    }
}

Queue *enqueue(Queue *head, int data, int priority) {
    Node *newNode = makeNode(data, priority);
    if (isEmpty(head)) {
        head->front = newNode;
        head->rear = newNode; 
    } else {
        Node *tmp = head->front;
        Node *prev = NULL;
        while (tmp != NULL && tmp->priority <= priority) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (prev == NULL) {
            newNode->next = tmp;
            head->front = newNode;
        } else {
            prev->next = newNode;
            newNode->next = tmp;
            if (tmp == NULL) {
                head->rear = newNode;
            }
        }
    }
    return head;
}

int dequeue(Queue *head) {
    if (isEmpty(head)) {
        return -1;
    } else {
        Node *tmp = head->front;
        int data = head->front->data;
        head->front = head->front->next;
        free(tmp);
        return data;
    }
}

int peek(Queue *head) {
    if (isEmpty(head)) {
        return -1;
    } else {
        return head->front->data;
    }
}

void display(Queue *head) {
    int data;
    Node *tmp = head->front;
    while (tmp != NULL) {
        data = tmp->data;
        printf("%d ", data);
        tmp = tmp->next;
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