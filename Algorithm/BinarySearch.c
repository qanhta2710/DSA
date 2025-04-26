#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void bubbleSort(int arr[], int n);
void binarySearch(int arr[], int beg, int end, int x);

int main() {
    int arr[MAX], n;
    int beg, end, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    getchar();
    scanf("%d", &x);
    bubbleSort(arr, n);
    beg = 0;
    end = n - 1;
    binarySearch(arr, beg, end, x);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void binarySearch(int arr[], int beg, int end, int x) {
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == x) {
            printf("Element %d found\n", x);
            return;
        } else if (arr[mid] < x) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    printf("Element %d not found in the array\n", x);
    return;
}