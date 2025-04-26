#include <stdio.h>
int main() {
    int arr[5][3], total_sales = 0, total_items = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter the sales of 3 items sold by saleman %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Total Sales By Salesman %d = ", i + 1);
        for (int j = 0; j < 3; j++) {
            total_sales = total_sales + arr[i][j];
        }
        printf("%d\n", total_sales);
        total_sales = 0;
    }
    for (int j = 0; j < 3; j++) {
        printf("Total Sales of Item %d = ", j + 1);
        for (int i = 0; i < 5; i++) {
            total_items = total_items + arr[i][j];
        }
        printf("%d\n", total_items);
        total_items = 0;
    }
    return 0;
}