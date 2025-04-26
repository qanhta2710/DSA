#include <stdio.h>
void move(int n, char source, char dest, char spare);

int main() {
    int n;
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    return 0;
}

void move(int n, char source, char dest, char spare) {
    if (n == 1) {
        printf("Move from %c to %c\n", source, dest);
    } else {
        move(n - 1, source, spare, dest);
        move(1, source, dest, spare);
        move(n - 1, spare, dest, source);
    }
}