#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include "bignum.c"

#ifndef ESSENTIALS_H
#define ESSENTIALS_H

typedef struct orderedPair {
    int x;
    int y;
} orderedPair;

#define MAX(i1, i2) (i1 > i2 ? i1 : i2)

float TIME_START, TIME_END;

void timeStart();
void timeEnd();
int isPrime(long long x);
int getFileLines(char *fname);
int getLineLength(char *fname, char sep);
orderedPair makePair(int x, int y);
void choose(int x, int y, bignum* ret);
void factorial(int x, bignum *ret);

#endif
