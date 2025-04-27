#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    struct DNode *prev;
    int data;
    struct DNode *next;
} DNode;

DNode *makeNode(int data);
DNode *createDoublyLinkedList(DNode *head);
void display(DNode *head);
DNode *addAtBeginning(DNode *head, int data);
DNode *addAtEnd(DNode *head, int data);
DNode *addBefore(DNode *head, int data, int value);
DNode *addAfter(DNode *head, int data, int value);
DNode *deleteAtBeginning(DNode *head);
DNode *deleteAtEnd(DNode *head);
DNode *deleteBefore(DNode *head, int value);
DNode *deleteAfter(DNode *head, int value);
void deleteList(DNode *head);

int main() {
    int choice, x, value;
    DNode *myNode = NULL;
    do
    {   
        printf("\n\n -----MAIN MENU-----");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            myNode = createDoublyLinkedList(myNode);
            break;
        case 2:
            display(myNode);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &x);
            myNode = addAtBeginning(myNode, x);
            break;
        case 4: 
            printf("Enter value: ");
            scanf("%d", &x);
            myNode = addAtEnd(myNode, x);
            break;
        case 5:
            printf("Enter value want to add before: ");
            scanf("%d", &value);
            printf("Enter value want to add: ");
            scanf("%d", &x);
            myNode = addBefore(myNode, x, value);
            break;
        case 6:             
            printf("Enter value want to add after: ");
            scanf("%d", &value);
            printf("Enter value want to add: ");
            scanf("%d", &x);
            myNode = addAfter(myNode, x, value);
            break;
        case 7:
            myNode = deleteAtBeginning(myNode);
            break;
        case 8:
            myNode = deleteAtEnd(myNode);
            break;
        case 9:
            printf("Delete before value: ");
            scanf("%d", &x);
            myNode = deleteBefore(myNode, x);
            break;
        case 10:
            printf("Delete after value: ");
            scanf("%d", &x);
            myNode = deleteAfter(myNode, x);
            break;
        case 11:
            deleteList(myNode);
            printf("Exiting...");
            break;
        }
    } while (choice != 11);
    return 0;
}

DNode *makeNode(int data) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

DNode *createDoublyLinkedList(DNode *head) {
    int n, data;
    DNode *current = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for nodes %d: ", i);
        scanf("%d", &data);
        DNode *newNode = makeNode(data);
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }
    return head;
}

void display(DNode *head) {
    DNode *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

DNode *addAtBeginning(DNode *head, int data) {
    DNode *newNode = makeNode(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

DNode *addAtEnd(DNode *head, int data) {
    DNode *newNode = makeNode(data);
    DNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

DNode *addBefore(DNode *head, int data, int value) {
    if (head->data == value) {
        head = addAtBeginning(head, data);
        return head;
    }
    
    DNode *current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Not found");
        return head;
    }
    DNode *newNode = makeNode(data);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;
    return head;
}

DNode *addAfter(DNode *head, int data, int value) {
    DNode *current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Not found");
        return head;
    }
    DNode *newNode = makeNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

DNode *deleteAtBeginning(DNode *head) {
    DNode *tmp = head;
    head = head->next;
    head->prev = NULL;
    free(tmp);
    return head;
}

DNode *deleteAtEnd(DNode *head) {
    DNode *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    DNode *tmp = current->next;
    current->next = NULL;
    free(tmp);
    return head;
}

DNode *deleteBefore(DNode *head, int value) {
    if (head->data == value) {
        printf("Error");
        return head;
    }
    DNode *current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Not found");
        return head;
    }
    DNode *nodeToDelete = current->prev;
    nodeToDelete->prev->next = current;
    current->prev = nodeToDelete->prev;
    free(nodeToDelete);
    return head;
}

DNode *deleteAfter(DNode *head, int value) {
    DNode *current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Not found");
        return head;
    }
    if (current->next == NULL) {
        printf("Error");
        return head;
    }
    DNode *nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = current;
    }
    free(nodeToDelete);
    return head;
}

void deleteList(DNode *head) {
    while (head != NULL) {
        DNode *curr = head;
        head = head->next;
        free(curr);
    }
}