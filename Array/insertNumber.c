#include <stdio.h>
#define MAX 100

int main() {
    int n, pos, k, arr[MAX];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be inserted: ");
    scanf("%d", &k);
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = k;
    n++;
    printf("The array after insertion of %d is: \n", k);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}