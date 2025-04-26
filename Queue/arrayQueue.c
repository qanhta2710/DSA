#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int queue[], int value);
int dequeue(int queue[]);
bool isEmpty(int queue[]);
bool isFull(int queue[]);
void display(int queue[]);
int peek(int queue[]);

int main() {
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(queue, x);
    }
    display(queue);
    printf("Front element: %d\n", peek(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    display(queue);
    return 0;
}

bool isEmpty(int queue[]) {
    return front == -1;
}
bool isFull(int queue[]) {
    return rear == MAX - 1;
}

void enqueue(int queue[], int value) {
    if (isFull(queue)) {
        printf("OVERFLOW\n");
        return;
    } else {
        if (isEmpty(queue)) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue(int queue[]) {
    if (isEmpty(queue)) {
        printf("UNDERFLOW\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
            return value;
        } else {
            front++;
            return value;
        }
    }
}

void display(int queue[]) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int peek(int queue[]) {
    if (isEmpty(queue)) {
        printf("UNDERFLOW\n");
        return -1;
    } else {
        return queue[front];
    }
}