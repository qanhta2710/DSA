#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

CNode *makeNode(int data);
CNode *createCircularLinkedList();
void display(CNode *head);
CNode *insertAtBeginning(CNode *head, int data);
CNode *insertAtEnd(CNode *head, int data);
CNode *deleteAtBeginning(CNode *head);
CNode *deleteAtEnd(CNode *head);

int main() {
    CNode *myNode = NULL;
    int choice;
    int x;
    do {
        printf("\n\n -----MAIN MENU-----");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\033[H\033[J");
                myNode = createCircularLinkedList();
                break;
            case 2:
                printf("\033[H\033[J");
                display(myNode);
                getch();
                break;
            case 3:
                printf("\033[H\033[J");
                printf("Enter value: ");
                scanf("%d", &x);
                myNode = insertAtBeginning(myNode, x);
                break;
            case 4:
                printf("\033[H\033[J");
                printf("Enter value: ");
                scanf("%d", &x);
                myNode = insertAtEnd(myNode, x);
                break;
            case 5:
                printf("\033[H\033[J");
                myNode = deleteAtBeginning(myNode);
                break;
            case 6:
                printf("\033[H\033[J");
                myNode = deleteAtEnd(myNode);
                break;
            case 7:
                printf("Exiting...");
                break;
        }
    } while (choice != 7);
}

CNode *makeNode(int data) {
    CNode *newNode = (CNode *)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

CNode *createCircularLinkedList() {
    int n, data;
    CNode *head = NULL, *tmp = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        CNode *newNode = makeNode(data);
        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    tmp->next = head;
    return head;
} 

void display(CNode *head) {
    CNode *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);   
}

CNode *insertAtBeginning(CNode *head, int data) {
    CNode *newNode = makeNode(data);
    CNode *current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

CNode *insertAtEnd(CNode *head, int data) {
    CNode *newNode = makeNode(data);
    CNode *current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

CNode *deleteAtBeginning(CNode *head) {
    CNode *tmp = head;
    CNode *current = head;
    while (current->next != head) {
        current = current->next;
    }
    head = head->next;
    current->next = head;
    free(tmp);
    return head;
}

CNode *deleteAtEnd(CNode *head) {
    CNode *current = NULL;
    CNode *tmp = head;
    while (tmp->next != head) {
        current = tmp;
        tmp = tmp->next;
    }
    current->next = head;
    free(tmp);
    return head;
}