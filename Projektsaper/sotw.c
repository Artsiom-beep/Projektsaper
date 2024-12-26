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

void rasp(int** a, char** b, int n, int m, int o, int p) {
    
    if (a[o][p] == 0) {
        a[o][p] = -2; 
        b[o - 1][p - 1] = '.'; 

       
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue; 
                int new_o = o + dx;
                int new_p = p + dy;

               
                if (new_o >= 1 && new_o <= n && new_p >= 1 && new_p <= m) {
                    if (a[new_o][new_p] == 0) {
                        rasp(a, b, n, m, new_o, new_p); 
                    }
                    else if (a[new_o][new_p] > 0) {
                        b[new_o - 1][new_p - 1] = a[new_o][new_p] + '0'; 
                        a[new_o][new_p] = -3; 
                    }
                }
            }
        }
    }
    else if (a[o][p] > 0) {
        
        b[o - 1][p - 1] = a[o][p] + '0';
        a[o][p] = -3; 
    }
}

int check(int** a, int n, int m, int *points) {
    (*points) = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == -2 || a[i][j] == -3) (*points)++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > 0) return 0;
            
        }
    }
    return 1;
}