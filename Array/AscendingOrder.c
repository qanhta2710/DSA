#include <stdio.h>
#define MAX 10
int main() {
    int n, pos, arr[10];
    int k;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    for (int i = 0;i < n; i++) {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number to be inserted : ");
    scanf("%d", &k);

    for (pos = 0; pos < n; pos++) {
        if (k < arr[pos]) {
            for (int j = n; j > pos; j--) {
                arr[j] = arr[j - 1];
            }
            arr[pos] = k;
            break;
        } else {
            arr[n] = k;
            break;
        }
    }
    n++;
    printf("\n The array after insertion of %d is : ", k);
    for (int i = 0; i < n; i++) {
        printf("\n arr[%d] = %d", i, arr[i]);
    }
}