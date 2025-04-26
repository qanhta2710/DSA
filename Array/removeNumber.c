#include <stdio.h>
#define MAX 100

int main() {
    int n, pos, arr[MAX];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of the number to be removed: ");
    scanf("%d", &pos);
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("The array after removing the number at position %d is:\n", pos);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}