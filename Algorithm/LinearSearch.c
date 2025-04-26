#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void LinearSearch(int arr[], int n, int x);

int main() {
    int arr[MAX];
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    LinearSearch(arr, n, x);
    return 0;
}

void LinearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d found at position %d\n", x, i + 1);
            return;
        }
    }
    printf("Element %d not found in the array\n", x);
    return;
}