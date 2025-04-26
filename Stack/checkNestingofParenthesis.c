#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

char stack[MAX]; 
int top = -1;
void push(char stack[], char value);
char pop(char stack[]);
bool isOpenBracket(char c);
bool isCloseBracket(char c);
bool isMatchingPair(char open, char close);

int main() {
    char str[MAX];
    printf("Enter an expression: ");
    fgets(str, MAX, stdin);
    for (int i = 0; i < strlen(str); i++) {
        if (isOpenBracket(str[i])) {
            push(stack, str[i]);
        } else if (isCloseBracket(str[i])) {
            if (top == -1) {
                printf("Invalid expression\n");
                return 0;
            } else {
                char open = pop(stack);
                if (!isMatchingPair(open, str[i])) {
                    printf("Invalid expression\n");
                    return 0;
                }
            }
        }
    }
    if (top == -1) {
        printf("Valid expression\n");
        return 0; 
    } else {
        printf("Invalid expression\n");
        return 0;
    }
}

void push(char stack[], char value) {
    stack[++top] = value;
}

char pop(char stack[]) {
    return stack[top--];
}

bool isOpenBracket(char c) {
    if (c == '(' || c == '[' || c == '{') {
        return true;
    }
    return false;
}

bool isCloseBracket(char c) {
    if (c == ')' || c == ']' || c == '}') {
        return true;
    }
    return false;
}
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    } else if (open == '[' && close == ']') {
        return true;
    } else if (open == '{' && close == '}') {
        return true;
    }
    return false;
}