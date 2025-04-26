#include <stdio.h>
int gcd(int a, int b); 

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) { // base case
        return a; 
    } else { // recursive case
        return gcd(b, a % b); // Euclidean algorithm
    }
}