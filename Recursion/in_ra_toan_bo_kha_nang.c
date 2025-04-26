#include <stdio.h>
#include <stdbool.h>
#define N 8

void solution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    // check if the queen is in the same column
    for (i = 0; i < row; i++) {
        if (board[i][col] == true) {
            return false;
        }
    }
    // check if the queen is in the upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == true) {
            return false;
        }
    }
    // check if the queen is in the lower left diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

void solveNQueen(int board[N][N], int row) {
    // base case : if all queens are placed
    if (row >= N) {
        solution(board);
    }
    // place queens by row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col) == true) {
            board[row][col] = 1;
            solveNQueen(board, row + 1);
            board[row][col] = 0; // delete queen if not safe
        }
    }
}

int main() {
    int board[N][N] = {0};
    solveNQueen(board, 0);
    return 0;
}