#include <stdio.h>
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, 2, 4, 6, 8};
    int arr3[] = {1, 3, 5, 7, 9};
    int *parr[] = {arr1, arr2, arr3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", *(parr[i] + j)); // = parr[i][j]
        }
        printf("\n");
    }
    return 0;
}