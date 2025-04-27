#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *makeNode(int data);
Node *createLinkedList();
void display(Node *head);
Node *insertAtBeginning(Node *head, int data);
Node *insertAtEnd(Node *head, int data);
Node *insertBeforeANode(Node *head, int data, int value);
Node *insertAfterANode(Node *head, int data, int value);
Node *deleteAtBeginning(Node *head);
Node *deleteAtEnd(Node *head);
Node *deleteANode(Node *head, int value);
void deleteLinkedList(Node *head);
Node *sort(Node *head);
Node *reverse(Node *head);

int main() {
    Node *myNode = NULL;
    int option;
    do
    {
        printf("\n ---MENU--- \n");
        printf("1. Create a Singly Linked List\n");
        printf("2. Display the Singly Linked List\n");
        printf("3. Insert a new Node at the Beginning\n");
        printf("4. Insert a new Node at the End\n");
        printf("5. Insert a new Node Before a Given Node\n");
        printf("6. Insert a new Node After a Given Node\n");
        printf("7. Delete a Node from the Beginning\n");
        printf("8. Delete a Node from the End\n");
        printf("9. Delete a Given Node\n");
        printf("10. Sort the list\n");
        printf("11. Reverse the list\n");
        printf("12. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\033[H\033[J");
                myNode = createLinkedList();
                break;
            case 2:
                printf("\033[H\033[J");
                display(myNode);
                break;
            case 3:
                printf("\033[H\033[J");
                printf("Enter the data for the new node: ");
                int data;
                scanf("%d", &data);
                myNode = insertAtBeginning(myNode, data);
                break;
            case 4:
                printf("\033[H\033[J");
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                myNode = insertAtEnd(myNode, data);
                break;  
            case 5:
                printf("\033[H\033[J"); 
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the value of the node after which you want to insert the new node: ");
                int value;
                scanf("%d", &value);
                myNode = insertBeforeANode(myNode, data, value);
                break;
            case 6:
                printf("\033[H\033[J");
                printf("Enter the data for the new node: ");
                scanf("%d", &data);
                printf("Enter the value of the node after which you want to insert the new node: ");
                scanf("%d", &value);
                myNode = insertAfterANode(myNode, data, value);
                break;
            case 7:
                printf("\033[H\033[J");
                printf("Deleting the first node...\n");
                myNode = deleteAtBeginning(myNode);
                break;
            case 8:
                printf("\033[H\033[J");
                printf("Deleting the last node...\n");
                myNode = deleteAtEnd(myNode);
                break;
            case 9:
                printf("\033[H\033[J");
                printf("Enter the value of the node you want to delete: ");
                scanf("%d", &value);
                myNode = deleteANode(myNode, value);
                break;
            case 10:
                printf("\033[H\033[J");
                printf("Sorting the list...\n");
                myNode = sort(myNode);
                break;
            case 11:
                printf("\033[H\033[J");
                printf("Reversing the list...\n");
                myNode = reverse(myNode);
                break;
            case 12:
                printf("\033[H\033[J");
                printf("Exiting...\n");
                deleteLinkedList(myNode);
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 12);
    return 0;
}

Node *makeNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *createLinkedList() {
    int n, data;
    Node *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    return head;
}

void display(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *insertAtEnd(Node *head, int data) {
    Node *newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
}

Node *insertBeforeANode(Node *head, int data, int value) {
    Node *newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    } else if (head->data == value) {
        newNode->next = head;
        head = newNode;
        return head;
    } else {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->next->data != value) {
            tmp = tmp->next;
        }
        if (tmp->next == NULL) {
            printf("Not Found");
            return head;
        } else {
            newNode->next = tmp->next;
            tmp->next = newNode;
            return head;
        }
    }
}

Node *insertAfterANode(Node *head, int data, int value) {
    Node *newNode = makeNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    } else {
        Node *tmp = head;
        while (tmp!= NULL && tmp->data != value) {
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            printf("Not Found");
            return head;
        } else if (tmp->next == NULL) {
            head = insertAtEnd(head, data);
            return head;
        } else {
            newNode->next = tmp->next;
            tmp->next = newNode;
            return head;
        }
    }
}

Node *deleteAtBeginning(Node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    } else {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}

Node *deleteAtEnd(Node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    } else if (head->next == NULL) {
        head = deleteAtBeginning(head);
        return head;
    } else {
        Node *tmp = head;
        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        Node *freeData = tmp->next;
        tmp->next = NULL;
        free(freeData);
        return head;
    }
}

Node *deleteANode(Node *head, int value) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    } else if (head->data == value) {
        head = deleteAtBeginning(head);
        return head;
    } else {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->next->data != value) {
            tmp = tmp->next;
        }
        if (tmp->next == NULL) {
            printf("Not Found\n");
            return head;
        } else {
            Node *deleteNode = tmp->next;
            tmp->next = tmp->next->next;
            free(deleteNode);
            return head;
        }
    }
}

void deleteLinkedList(Node *head) {
    Node *tmp = head;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node *sort(Node *head) {
    Node *tmp1 = head;
    while (tmp1 != NULL) {
        Node *tmp2 = tmp1->next;
        while (tmp2 != NULL) {
            if (tmp1->data > tmp2->data) {
                int tmp = tmp1->data;
                tmp1->data = tmp2->data;
                tmp2->data = tmp;
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    return head;
}

Node *reverse(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current ->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
