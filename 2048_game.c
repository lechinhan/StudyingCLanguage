#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[4][4];
int lineDir[] = {1, 0, -1, 0};
int columnDir[] = {0, 1, 0, -1};
void addPiece() {
    srand(time(0));
    int line, column;
    while (1) {
        line = rand() % 4;
        column = rand() % 4;
        if (board[line][column] == 0) {
            break;
        }
    }
    board[line][column] = 2;
}
int checkWin() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] >= 2048) {
                return 1;
            }
        }
    }
    return 0;
}
void printUI() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                printf("%4c", '.');
            } else {
                printf("%4d", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Commands:\nn: New Game, q: Quit Game\nw: Up, s: Down, d: Right, a: "
           "Left\n");
}
void newGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    addPiece();
}
int canMove(int line, int column, int nextLine, int nextColumn) {
    if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
        board[line][column] != board[nextLine][nextColumn] &&
            board[nextLine][nextColumn] != 0) {
        return 0;
    }
    return 1;
}
void Move(int direction) {
    int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
    if (direction == 0) {
        startLine = 3;
        lineStep = -1;
    }
    if (direction == 1) {
        startColumn = 3;
        columnStep = -1;
    }
    int movePos = 1, canAddPiece = 0;
    do {
        movePos = 0;
        for (int i = startLine; i >= 0 && i < 4; i += lineStep) {
            for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
                int nextI = i + lineDir[direction],
                    nextJ = j + columnDir[direction];
                if (board[i][j] && canMove(i, j, nextI, nextJ)) {
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePos = canAddPiece = 1;
                }
            }
        }
    } while (movePos);
    if (canAddPiece)
        addPiece();
}
int main(void) {
    printf("\n\tGame 2048\n\nNhan phim bat ky de bat dau");
    getch();
    newGame();
    while (1) {
        if (checkWin()) {
            system("cls");
            printf("Chuc mung ban da thang !\n");
            printUI();
            printf("\nNhan phim bat ky de ket thuc");
            getch();
            exit(0);
        }
        system("cls");
        printUI();
        switch (getch()) {
        case 'n': {
            system("cls");
            printf("Nhan y de khoi dong lai.\nNhan phim bat ky de tiep tuc");
            if (getch() == 'y') {
                newGame();
            }
            break;
        }
        case 'q':
            system("cls");
            printf("Ban thuc su muon ket thuc ?\n");
            printf("Nhan y de ket thuc.\nNhan phim bat ky de tiep tuc.");
            if (getch() == 'y') {
                system("cls");
                printf("Tro choi ket thuc !\nNhan phim bat ky de ket thuc");
                getch();
                exit(0);
            } else {
                break;
            }
        case 's':
            Move(0);
            break;
        case 'd':
            Move(1);
            break;
        case 'w':
            Move(2);
            break;
        case 'a':
            Move(3);
        default:
            break;
        }
    }
    return 0;
}