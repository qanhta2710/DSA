#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int stack[MAX], top = -1;
void push(int stack[], int value);
bool isFull(int stack[]);
bool isEmpty(int stack[]);
int pop(int stack[]);
int peek(int stack[]);

int main() {
    int option, value;
    do {
        printf("\n ---MENU--- \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int x;
            printf("Enter the value to push: ");
            scanf("%d", &x);
            push(stack, x);
            break;
        case 2:
            value = pop(stack);
            if (value != -1) {
                printf("Popped %d\n", value);
            } else {
                printf("STACK UNDERFLOW\n");
            }
            break;
        case 3:
            value = peek(stack);
            if (value != -1) {
                printf("Top of the stack: %d\n", value);
            } else {
                printf("STACK UNDERFLOW\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            break;
        }
    } while (option != 4);
    return 0;
}

bool isFull(int stack[]) {
    if (top == MAX - 1) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(int stack[]) {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(int stack[], int value) {
    if (isFull(stack)) {
        printf("STACK OVERFLOW\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

int pop(int stack[]) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int peek(int stack[]) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        return stack[top];
    }
}