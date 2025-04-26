#include <stdio.h>
#define MAX 100

int main() {
    int n, k, arr[MAX];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be removed: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
        }
    }
    printf("The array after removing %d is:\n", k);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}