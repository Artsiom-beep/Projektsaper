#ifndef _SOTW
#define _SOTW

#include <stdlib.h>
#include <time.h>



void spawnmines(int **a, int n, int m);
void write(char** b, int n, int m);
void wheremines(int** a, int n, int m);
void rasp(int** a, char** b, int n, int m, int o, int p);
int check(int** a, int n, int m);
#endif
