#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1; 
void push(int stack[], int value);
int pop(int stack[]);

int main() {
    int n, x;
    int arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(stack, x);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void push(int stack[], int value) {
    stack[++top] = value;
}

int pop(int stack[]) {
    return stack[top--];
}