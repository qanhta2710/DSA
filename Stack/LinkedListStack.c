#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *makeNode(int data);
Node *top = NULL;
Node *push(Node *head, int data);
bool isEmpty(Node *head);
Node *pop(Node *head);
int peek(Node *head);

int main() {
    int option, value;
    do
    {
        printf("\n ---MENU--- \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                int x;
                printf("Enter the value to push: ");
                scanf("%d", &x);
                top = push(top, x);
                break;
            case 2:
                if (isEmpty(top)) {
                    printf("STACK UNDERFLOW\n");
                } else {
                    printf("Popped %d\n", top->data);
                    top = pop(top);
                }
                break;
            case 3:
                value = peek(top);
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
                printf("Invalid option\n");
        }
    } while (option != 4);
}

Node *makeNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Node *head) {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

Node *push(Node *head, int data) {
    Node *newNode = makeNode(data);
    if (isEmpty(head)) {
        head = newNode;
        return head;
    } else {
        newNode->next = head;
        head = newNode;
        return head;
    }
}

Node *pop(Node *head) {
    Node *tmp = head;
    head = head ->next;
    free(tmp);
    return head;
}

int peek(Node *head) {
    if (isEmpty(head)) {
        return -1;
    } else {
        return head->data;
    }
}

