#include <stdio.h>
#define MAX 100
int main() {
    int n1, n2, m, arr1[MAX], arr2[MAX], sorted[MAX];
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    m = n1 + n2;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            sorted[k] = arr1[i];
            i++;
            k++;
        } else {
            sorted[k] = arr2[j];
            j++;
            k++;
        }
    }
    for (int a1 = i; a1 < n1; a1++) {
        sorted[k] = arr1[a1];
        k++;
    }
    for (int a2 = j; a2 < n2; a2++) {
        sorted[k] = arr2[a2];
        k++;
    }
    printf("The merged array is:\n");
    for (int i = 0; i < m; i++) {
        printf("sorted[%d] = %d\n", i, sorted[i]);
    }
    return 0;
}