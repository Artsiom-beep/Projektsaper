#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sotw.h"

void clear_console() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}


int main() {
    srand(time(NULL));
    int n = 9, m = 9;
  
    int** a = (int**)malloc((n + 2) * sizeof(int*));
    for (int i = 0; i < n+2; i++) {
        a[i] = (int*)malloc((m + 2) * sizeof(int));
        for (int j = 0; j < m + 2; j++) {
            a[i][j] = -4;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 0;
        }
    }
    

    int o, p;

    scanf_s("%d%d", &o, &p);
    a[o][p] = -2;
    spawnmines(a, n, m);
    wheremines(a, n, m);

    char** b = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        b[i] = (char*)malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            if (a[i + 1][j + 1] == 0)
                b[i][j] = '*';
            else if (a[i + 1][j + 1] == -1)
                b[i][j] = '@';
            else if (a[i + 1][j + 1] == -2)
                b[i][j] = 'P';
            else if(a[i+1][j+1])
                b[i][j] = a[i+1][j+1] + '0';
        }
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    write(b, n, m);
   


    for (int i = 0; i < n+2; i++) {
        free(a[i]);
    }
    free(a);


    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    printf("A.\n");
    scanf_s("%d", &p);
    clear_console();
    printf("B.\n");


    return 0;
}
