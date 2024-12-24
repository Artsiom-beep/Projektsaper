#include "sotw.h"
#include <stdlib.h>
#include <time.h>

void spawnmines(int** a, int n, int m) {
    int mines = 0;

    while (mines < 10) {
        int x = rand() % m + 1;
        int y = rand() % n + 1;

        if (a[y][x] == 0) {
            a[y][x] = -1;
            mines++;
        }
    }
}

void write(char** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
}

void wheremines(int** a, int n, int m) {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == -1) {
                if (a[i - 1][j - 1] >= 0) a[i - 1][j - 1]++;
                if (a[i - 1][j] >= 0) a[i - 1][j]++;
                if (a[i - 1][j + 1] >= 0) a[i - 1][j + 1]++;
                if (a[i][j - 1] >= 0) a[i][j - 1]++;
                if (a[i][j + 1] >= 0) a[i][j + 1]++;
                if (a[i + 1][j - 1] >= 0) a[i + 1][j - 1]++;
                if (a[i + 1][j] >= 0) a[i + 1][j]++;
                if (a[i + 1][j + 1] >= 0) a[i + 1][j + 1]++;
            }

        }
    }

}

void rasp(int** a, char** b, int n, int m) {




}