#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert();
int delete();
int peek();
void display();

int main() {
    int choice, val;
    do {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                val = delete();
                if (val != -1) {
                    printf("\nThe number deleted is %d", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("\nThe first value in queue is: %d", val);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting...");
                break;
        }
    } while (choice != 5);
    return 0;
}

void insert() {
    int val;
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &val);
    if (front == 0 && rear == MAX - 1) {
        printf("\nOVERFLOW");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    } else if (front != 0 && rear == MAX - 1) {
        rear = 0;
        queue[rear] = val;
    } else {
        rear++;
        queue[rear] = val;
    }
}

int delete() {
    int val;
    if (front == -1 && rear == -1) {
        printf("\nUNDERFLOW");
        return -1;
    } else if (front == rear) {
        val = queue[front];
        front = rear = -1;
    } else if (front == MAX - 1) {
        val = queue[front];
        front = 0;
    } else {
        val = queue[front];
        front++;
    }
    return val;
}

int peek() {
    if (front == -1 && rear == -1) {
        printf("\nUNDERFLOW");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("\nUNDERFLOW");
        return;
    }
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        return;
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        return;
    }
}
