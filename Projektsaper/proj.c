#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sotw.h"

void clear_console() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}

typedef struct {
    char name[255];
    int score;
} player;

player top[6];


int main() {
    
    int points = 0;
    FILE* text = fopen("Score.txt", "rt");
    for (int i = 0; i < 5; i++) {
        char t[255];
        int y;
        fscanf_s(text, "%s", t, sizeof(t));
        fscanf_s(text, "%d", &y);
        strcpy_s(top[i].name, sizeof(top[i].name), t);
        top[i].score = y;
        //printf("%15s %6d \n", top[i].name, top[i].score);

    }
    fclose(text);
    printf("Welcome Player! Choose difficulty: \nFirst level: 9x9 10 mines     To choose print 1\nSecond level: 16x16 40 mines      To choose print 2\nThird level: 16x30 99 mines      To choose print 3\nLevel:");
    int level, n, m;
    scanf_s("%d", &level);
    if (level > 3 || level < 1) {
        printf("Choose from 1 to 3!");
        scanf_s("%d", &level);
    }
    if (level == 1) {
        n = 9;
        m = 9;
    }
    if (level == 2) {
        n = 16;
        m = 16;
    }
    if (level == 3) {
        n = 16;
        m = 30;
    }
    printf("Hello Player! Insert your first position: ");

    srand(time(NULL));
    

    

    int** a = (int**)malloc((n + 2) * sizeof(int*));
    for (int i = 0; i < n + 2; i++) {
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
    if (o < 1 || o>n || p < 1 || p>m){ 
        printf("Choose from 1 to %d and from 1 to %d!", n, m);
        scanf_s("%d%d", &o, &p);
        }
    a[o][p] = -2;
    spawnmines(a, n, m, level);
    a[o][p] = 0;
    wheremines(a, n, m);

    char** b = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        b[i] = (char*)malloc(m * sizeof(char));
        for (int j = 0; j < m; j++) {
            b[i][j] = '#';
        }
    }

    
    

    printf("\n");
    rasp(a, b, n, m, o, p);

   

    printf("\n");

    write(b, n, m);
    char symb;
    bool winner = true;
    while (check(a, n, m, &points) == 0) {
        clear_console();
        printf("Current map:\n");
        write(b, n, m);
        points *= level;
        printf("Score: %d\n", points);
        printf("Flag (f) or dig (r)?\n");
        
        A1:
        getchar();
        scanf_s("%c", &symb);
        scanf_s("%d%d", &o, &p);
        if (symb == 'r') {
            if (b[o - 1][p - 1] == 'F') {
                printf("Illegal command! Try enter command again:\n");
                goto A1;
            }
     
            if (a[o][p] == -1) {
                winner = false;
                break;
            }
            if (a[o][p] == -2 || a[o][p] == -3) {
                printf("Illegal command! Try enter command again:\n");
                goto A1;
            }
            
            printf("\n");
            rasp(a, b, n, m, o, p);


            /*for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < m + 2; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            */

            
        }
        else if (symb == 'f') {
            if (b[o - 1][p - 1] == '#')
                b[o - 1][p - 1] = 'F';
            else if (b[o - 1][p - 1] == 'F')
                b[o - 1][p - 1] = '#';
            else {
                printf("Illegal command! Try enter command again:\n");
                goto A1;
            }
        }
        else {
            printf("Illegal command! Try enter command again:\n");
            goto A1;
        }
    }



    if (winner) {
        printf("YOU WON!\nEnter your name:\n");
    }
    else {
        printf("GAME OVER!\nEnter your name:\n");
    }

    char im[254];
    //scanf_s("%[^\n]", &im, sizeof(im));
    scanf_s("%s", &im, sizeof(im));
    
    for (int i = 0; i < 5; i++) {
        if (top[i].score < points) {
           
            for (int j = 4; j > i; j--) {
                strcpy_s(top[j].name, sizeof(top[j].name), top[j - 1].name);
                top[j].score = top[j - 1].score;

            }
            
            strcpy_s(top[i].name, sizeof(top[i].name), im);
            
            top[i].score = points;
            break;
        }
    }


    for (int i = 0; i < n+2; i++) {
        free(a[i]);
    }
    free(a);


    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    FILE* text2 = fopen("Score.txt", "wt");
    for (int i = 0; i < 5; i++) {
       
        fprintf(text2, "%s\n", top[i].name);
        fprintf(text2, "%d\n", top[i].score);
        
        printf("%15s %6d \n", top[i].name, top[i].score);

    }
    fclose(text);
    
   
    
    

    return 0;
}
