/****************************************************
 *        Matrix Multiplication Using Pthread       *
 ****************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define TYPE float

void initrandom(void);
void generateMatrix(TYPE **A, int rA, int cA);
void mallocMatrix(TYPE ***A, int rA, int cA);
void prnMatrix(TYPE **A, int rA, int cA);
void Mulitiplication(TYPE **A, TYPE **B, TYPE **C, int rA,int rB, int cB);
TYPE rnd_int(int i);