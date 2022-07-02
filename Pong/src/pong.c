#include <stdio.h>
#include <math.h>

void field(int x, int y);
void map();
void ball_logic();
void move();

int pl1 = 11;
int pl2 = 11;
char movePl;
int count1 = 0;
int count2 = 0;

// ball
int ball_posX = 12;
int ball_posY = 40;
int ball_vecX = 1;
int ball_vecY = 1;


int main() {
    while (1) {
        map();
        move();
        if (movePl == 'v')
            return 0;
        if (count1 == 21) {
            printf("Player 1 win!");
            return 0;
        }
        if (count2 == 21) {
            printf("Player 2 win!");
            return 0;
        }
        ball_logic();
        printf("\033[0d\033[2J");
    }
    return 0;
}

void move() {
    scanf("%c", &movePl);
    if (movePl == 'a') {
        if (pl1 - 1 > 0)
            pl1 -= 1;
    }
    if (movePl == 'z') {
        if (pl1 + 3 < 24)
            pl1 += 1;
    }
    if (movePl == 'k') {
        if (pl2 - 1 > 0)
            pl2 -= 1;
    }
    if (movePl == 'm') {
        if (pl2 + 3 < 24)
            pl2 += 1;
    }
}

void ball_logic() {
    if (ball_posX == 23 || ball_posX == 1) {
        ball_vecX = -ball_vecX;
    } else if (ball_posY == 4 && ((ball_posX == pl1) ||
    (ball_posX == pl1 + 1) || (ball_posX == pl1 + 2))) {
        ball_vecY = -ball_vecY;
    } else if (ball_posY == 75 && ((ball_posX == pl2) ||
    (ball_posX == pl2 + 1) || (ball_posX == pl2 + 2))) {
        ball_vecY = -ball_vecY;
    } else if (ball_posY == 0) {
        count2++;
        ball_posX = 12;
        ball_posY = 35;
    } else if (ball_posY == 79) {
        count1++;
        ball_posX = 12;
        ball_posY = 35;
    }
    ball_posX += ball_vecX;
    ball_posY += ball_vecY;
}

void field(int x, int y) {
    char a = ' ';
    if (x == 0 || x == 24)
        a = '-';
    if (y == 0 || y == 79 || (y == 40 && x % 2))
        a = '|';
    if (y == 3 && (x == pl1 || x == pl1 + 1 || x == pl1 + 2))
        a = '|';
    if (y == 76 && (x == pl2 || x == pl2 + 1 || x == pl2 + 2))
        a = '|';
    if (y == ball_posY && x == ball_posX)
        a = '*';
    printf("%c", a);
}

void map() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 6 && j == 33) {
                printf("%2d", count1);
                continue;
            }
            if (i == 6 && j == 45) {
                printf("%2d", count2);
                continue;
            }
            if (i == 6 && (j == 47|| j == 48)) {
                continue;
            }
            field(i, j);
        }
        printf("\r\n");
    }
}
