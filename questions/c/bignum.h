#include <stdio.h>
#include <math.h>

#ifndef BIGNUM_H
#define BIGNUM_H

#define	MAXDIGITS	 200			/* maximum length bignum */ 

#define PLUS		 1			/* positive sign bit */
#define MINUS		-1			/* negative sign bit */

#define MAX(i1, i2) (i1 > i2 ? i1 : i2)		/* return larger value */

typedef struct {
        char digits[MAXDIGITS];         /* represent the number */
		int signbit;			/* 1 if positive, -1 if negative */ 
        int lastdigit;			/* index of high-order digit */
} bignum;

void print_bignum(bignum *n);
void int_to_bignum(int s, bignum *n);
void initialize_bignum(bignum *n);
void copy_bignum(bignum *toCopy, bignum *toPaste);
void add_bignum(bignum *a, bignum *b, bignum *c);
void subtract_bignum(bignum *a, bignum *b, bignum *c);
int compare_bignum(bignum *a, bignum *b);
void zero_justify(bignum *n);
void digit_shift(bignum *n, int d);
void multiply_bignum(bignum *a, bignum *b, bignum *c);
void divide_bignum(bignum *a, bignum *b, bignum *c);

#endif