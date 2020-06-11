#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 5
#define MINE -1
/*Mảng B lưu bảng đồ mìn*/
int B[M][N];
/*Mảng T lưu trạng thái các ô*/
int T[M][N];

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = 0;
            T[i][j] = 0;
        }
    }
    B[1][2] = -1;
    B[3][1] = -1;
}
void count_mines() {
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (B[r][c] == MINE) {
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i != 0 || j != 0) {
                            if (r + i >= 0 && r + i < M && c + j >= 0 &&
                                c + j < N) {
                                if (B[r + i][c + j] != -1) {
                                    B[r + i][c + j] += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void printMap2() {
    printf("0 ");
    for (int j = 1; j <= N; j++)
        printf("%d ", j);
    printf("\n");
    for (int i = 0; i < M; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < N; j++) {
            if (T[i][j] == 0)
                printf("# ");
            else {
                if (B[i][j] == MINE)
                    printf("x ");
                else if (B[i][j] == 0)
                    printf(". ");
                else
                    printf("%d ", B[i][j]);
            }
        }
        printf("\n");
    }
}
int count_remain() {
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (T[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}
void open_cell_3(int r, int c) {
    if (T[r][c] == 1) {
        return;
    } else {
        T[r][c] = 1;
        if (B[r][c] == 0) {
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i != 0 || j != 0) {
                        if (r + i >= 0 && r + i < M && c + j >= 0 &&
                            c + j < N) {
                            if (T[r + i][c + j] == 0) {
                                open_cell_3(r + i, c + j);
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(void) {
    init();
    count_mines();
    int r, c;
    while (1) {
        system("cls");
        printMap2();
        printf("Nhap so hang: ");
        scanf("%d", &r);
        printf("Nhap so cot: ");
        scanf("%d", &c);
        open_cell_3(r - 1, c - 1);
        if (count_remain() == 2) {
            system("cls");
            printMap2();
            printf("\nChuc mung! Ban da thang\n");
            break;
        }
        if (B[r - 1][c - 1] == MINE) {
            system("cls");
            printMap2();
            printf("\nChuc mung! Ban da thua\n");
            break;
        }
    }
    return 0;
}