#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#ifndef ESSENTIALS_H
#define ESSENTIALS_H

float TIME_START, TIME_END;

void timeStart();
void timeEnd();
int isPrime(long long x);
int getFileLines(char *fname);
int getLineLength(char *fname);

#endif