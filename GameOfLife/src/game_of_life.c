#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define H 25
#define W 80

int input(int a[H][W], int c[H][W]);
void map(int a[H][W]);
void change(int a[H][W], int b[H][W]);
void copy(int a[H][W], int b[H][W]);
int check(int a[H][W], int b[H][W]);

int main(int argc, char *argv[]) {
    (void) argc;
    int a[H][W], c[H][W];
    int speed = strtol(argv[1], NULL, 10);
    if (input(a, c) == 0) {
        int gen = 0, b[H][W];
        while (gen <= 3000) {
            map(a);
            change(a, b);
            if (check(a, b) == 0)
                break;
            copy(a, b);
            usleep(speed);
            system("clear");
            printf("Скорость - %d\n", speed);
            printf("Поколение - %d\n", gen);
            gen++;
            if (check(a, c) == 0)
                break;
        }
    } else {
        printf("n/a"); }
    return 0;
}
int input(int a[H][W], int c[H][W]) {
    int z = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (scanf("%d", &a[i][j]) == 1 && (a[i][j] == 0 || a[i][j] == 1)) {
                c[i][j] = a[i][j];
            } else {
                z = 1;
                break;
            }
        }
    return z;
}
void change(int a[H][W], int b[H][W]) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            int z = 0;
            for (int k = -1; k <= 1; k++)
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0)
                        continue;
                    if (a[(H + i + l)%H][(W + j + k)%W] == 1)
                        z++; }
        if (a[i][j] && (z == 2 || z == 3))
            b[i][j] = 1;
        else if (!a[i][j] && z == 3)
            b[i][j] = 1;
        else
            b[i][j] = 0;
        }
}
void map(int a[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == 1)
                printf("#");
            else
                printf(".");
        }
        if (i != H) {
            printf("\n");
        }
    }
}
void copy(int a[H][W], int b[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            a[i][j] = b[i][j];
        }
    }
}
int check(int a[H][W], int b[H][W]) {
    int z = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == b[i][j])
                continue;
            else
                z = 1;
        }
    }
    return z;
}
