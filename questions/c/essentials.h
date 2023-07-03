#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include "bignum.c"

#ifndef ESSENTIALS_H
#define ESSENTIALS_H

typedef struct orderedPair {
    int x;
    int y;
} orderedPair;

#define MAX(i1, i2) (i1 > i2 ? i1 : i2)
#define MIN(i1, i2) (i1 < i2 ? i1 : i2)

double TIME_START, TIME_END;

void timeStart();
void timeEnd();
int isPrime(long long x);
void printDynamicMatrix(int **matrix, int rows, int* modifiedCols);
int getFileLines(char *fname);
int getLineLength(char *fname, char sep, int lineNum);
orderedPair makePair(int x, int y);
bignum bignum_pow(int base, int exp);
void choose(int x, int y, bignum *ret);
void factorial(int x, bignum *ret);
int *arrCopy(int *toCopy, int size);
void bignumIntAdd(int i, int j, bignum *c);
void bignumIntSubtract(int i, int j, bignum *c);
void bignumIntMultiply(int i, int j, bignum *c);
void bignumIntDivide(int i, int j, bignum *c);
int seenIn(int val, long long *arr, int size);
int posSeenIn(int val, long long *arr, int size);
bool charsSeenIn(char* val, int *arr, int arrsize, int valsize);
int noCharsSeenIn(char* val, int *arr, int arrsize, int valsize);
bool equalPairs(orderedPair a, orderedPair b);
bool isPandigital(long long x, int digitLen, bool includeZero);
int noDigits(long long x);
int cmpfunc (const void * a, const void * b);
unsigned long long reverseNum(long long x);
bool isPalindrome(long long x);
int sieve(long long** primes, int n);

#endif
