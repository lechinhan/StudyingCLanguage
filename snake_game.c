#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define maxLine 20
#define maxColumn 60
int score = 0, lose = 0, speed = 20;
enum status { UP, DOWN, LEFT, RIGHT };
void delay(int miliSec) {
    clock_t start_time = clock();
    while (clock() < start_time + miliSec)
        ;
}
struct Point {
    int X, Y;
};
struct Snake {
    int n;
    struct Point Node[100];
    enum status stt;
};
struct Food {
    struct Point point;
};
void gotoxy(int x, int y) {
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}
void turnOffCursor() {
    CONSOLE_CURSOR_INFO CURSOR;
    CURSOR.dwSize = 1;
    CURSOR.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSOR);
}
void initSnake(struct Snake* snake) {
    snake->n = 2;
    snake->Node[0].X = 3;
    snake->Node[0].Y = 3;
    snake->stt = DOWN;
}
void initFood(struct Food* food) {
    srand(time(NULL));
    food->point.Y = 1 + rand() % 18;
    food->point.X = 1 + rand() % 40;
}
void displayMap() {
    gotoxy(0, 0);
    putchar(201);

    gotoxy(0, 20);
    putchar(200);

    gotoxy(60, 0);
    putchar(187);

    gotoxy(60, 20);
    putchar(188);
    for (int i = 1; i < maxLine; i++) {
        gotoxy(0, i);
        putchar(186);
        gotoxy(60, i);
        putchar(186);
    }
    for (int i = 1; i < maxColumn; i++) {
        gotoxy(i, 0);
        putchar(205);
        gotoxy(i, 20);
        putchar(205);
    }
}
void displayCharacter(struct Snake snake, struct Food food) {
    gotoxy(food.point.X, food.point.Y);
    putchar(233);
    for (int i = 0; i < snake.n; i++) {
        gotoxy(snake.Node[i].X, snake.Node[i].Y);
        if (i == 0) {
            putchar(178);
        } else if (i == (snake.n) - 1) {
            putchar(32);
        } else {
            putchar(176);
        }
    }
    gotoxy(0, maxLine + 1);
    printf("Score: %d\tSpeed: %dkm/h", score, speed);
}
void checkLose(struct Snake snake) {
    for (int i = 1; i < (snake.n); i++) {
        if ((snake.Node[0].X) == (snake.Node[i].X) &&
            (snake.Node[0].Y) == (snake.Node[i].Y)) {
            lose = -1;
        }
    }
    if (snake.Node[0].X <= 0 || snake.Node[0].Y <= 0 ||
        snake.Node[0].X >= maxColumn || snake.Node[0].Y >= maxLine) {
        lose = -1;
    }
    return;
}
void moveTheHead(struct Snake* snake) {
    switch (snake->stt) {
    case UP:
        snake->Node[0].Y--;
        break;
    case DOWN:
        snake->Node[0].Y++;
        break;
    case LEFT:
        snake->Node[0].X--;
        break;
    case RIGHT:
        snake->Node[0].X++;
        break;
    default:
        break;
    }
}
void Move(struct Snake* snake) {
    for (int i = (snake->n); i > 0; i--) {
        (snake->Node[i]) = (snake->Node[i - 1]);
    }
    if (kbhit()) {
        switch (_getch()) {
        case 'w':
            if (snake->stt == DOWN) {
                break;
            }
            snake->stt = UP;
            break;
        case 's':
            if (snake->stt == UP) {
                break;
            }
            snake->stt = DOWN;
            break;
        case 'a':
            if (snake->stt == RIGHT) {
                break;
            }
            snake->stt = LEFT;
            break;
        case 'd':
            if (snake->stt == LEFT) {
                break;
            }
            snake->stt = RIGHT;
            break;
        case 'e':
            speed += speed < 150 ? 10 : 0;
            break;
        case 'q':
            speed -= speed > 50 ? 10 : 0;
            break;
        case ' ':
            getch();
            break;
        default:
            break;
        }
    }
    moveTheHead(snake);
}
void checkEatFood(struct Snake* snake, struct Food* food) {
    if ((snake->Node[0].X == food->point.X) &&
        (snake->Node[0].Y == food->point.Y)) {
        score += 10;
        (snake->n)++;
        switch (snake->stt) {
        case RIGHT:
            snake->Node[snake->n].X--;
            break;
        case UP:
            snake->Node[snake->n].Y++;
            break;
        case DOWN:
            snake->Node[snake->n].Y--;
            break;
        case LEFT:
            snake->Node[snake->n].X++;
            break;
        default:
            break;
        }
        initFood(food);
    }
}
int main(void) {
    turnOffCursor();
    system("cls");
    struct Snake snake;
    struct Food food;
    initSnake(&snake);
    initFood(&food);
    displayMap();
    while (1) {
        Move(&snake);
        checkEatFood(&snake, &food);
        checkLose(snake);
        if (lose == -1) {
            gotoxy(0, maxLine + 1);
            printf("\nChuc mung ban da thua\nYour best Score: %d\n", score);
            exit(0);
        }
        displayCharacter(snake, food);
        delay(200 - speed);
    }
    return 0;
}
