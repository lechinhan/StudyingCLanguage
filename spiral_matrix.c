/*
    The idea of the algorithm is that we set the out size row and column of the
   matrix. Then we shrink the matrix 1 row and 1 column then we set it again
*/
#include <stdio.h>

#define SIZE 10
int mat[SIZE][SIZE];

void spiral(void);
void display(void);

int main(void) {
    spiral();
    display();
    return 0;
}
void spiral(void) {
    int row = SIZE - 1;
    int col = SIZE - 1;
    int value = SIZE * SIZE;
    int c = 0; // The var c use for shrinking the area of the matrix
    while (c < SIZE / 2) {
        // Set the top row's value
        for (int i = c; i < col - c; i++) {
            mat[c][i] = value--;
        }
        // Set the right column's value
        for (int i = c; i < row - c; i++) {
            mat[i][col - c] = value--;
        }
        // Set the bottom row's value
        for (int i = col - c; i > c; i--) {
            mat[row - c][i] = value--;
        }
        // Set the left column's value
        for (int i = row - c; i > c; i--) {
            mat[i][c] = value--;
        }
        c++;
        if (SIZE % 2 != 0) {
            // For the center point
            mat[SIZE / 2][SIZE / 2] = value;
        }
    }
}
void display(void) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}