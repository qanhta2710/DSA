#include <stdio.h>
#define MAX 10

void read_array(int arr[], int n);
int find_min(int arr[], int n);
int find_max(int arr[], int n);
void interchange(int arr[], int n);
void print_new(int arr[], int n);

int main() {
    int n, arr[MAX], min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    read_array(arr, n);
    interchange(arr, n);
    print_new(arr, n);
    return 0;
}

void read_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

int find_min(int arr[], int n) {
    int min = arr[0], pos;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

int find_max(int arr[], int n) {
    int max = arr[0], pos;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

void interchange(int arr[], int n) {
    int min_pos = find_min(arr, n);
    int max_pos = find_max(arr, n);
    int tmp = arr[min_pos];
    arr[min_pos] = arr[max_pos];
    arr[max_pos] = tmp;
}

void print_new(int arr[], int n) {
    printf("The new array is: \n");
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] =  %d\n", i, arr[i]);
    }
}