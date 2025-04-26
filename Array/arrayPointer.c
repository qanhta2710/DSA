#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int *p1, *p2;
    p1 = &arr[0];
    p2 = &arr[6];
    while (p1 <= p2) {
        printf("%d ", *p1);
        p1++;
    }
    return 0;
}