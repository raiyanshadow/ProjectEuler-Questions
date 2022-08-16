#include "essentials.h"

void timeStart()
{
    TIME_START = (float) clock () / CLOCKS_PER_SEC; 
}

void timeEnd()
{
    TIME_END = (float) clock () / CLOCKS_PER_SEC;
    printf("Time elapsed: %f", TIME_END-TIME_START);
}

int isPrime(long long x)
{   
    if (x < 2)
    {
        return 2;
    }
    long long ret = 2;
    while (ret * ret <= x)
    {
        if (x % ret == 0)
        {
            return 0;
        }
        ret++;
    }
    return 1;
}

void printDynamicMatrix(int **matrix, int rows, int* modifiedCols) {
  int i, j;
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < modifiedCols[i]; j++)
        {
            printf("%d ", matrix[i][j]);
            
        }
        printf("\n");
    }  
}

int getFileLines(char *fname)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int ret = 0;

    while (ch != EOF)
    {
        ch = fgetc(f);
        if (ch == '\n')
        {
            ret++;
        }
    }

    fclose(f);

    return ret + 1;
}

int getLineLength(char *fname, char sep, int lineNum)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int ret = 0;
    char tmpsep = sep;

    if (lineNum != 1)
    {
        for (int i = 0; i < lineNum - 1; )
        {
            ch = fgetc(f);
            if (ch == '\n')
            {
                i++;
            }
        }
        ch = fgetc(f);
    }

    while (ch != '\n' && ch != EOF)
    {
        ch = fgetc(f);
        if (tmpsep == 0)
        {
            sep = ch;
        }
        if (ch == sep && ch != '\n' && ch != EOF)
        {
            ret++;
        }
    }
    
    fclose(f);

    if (tmpsep == 0)
    {
        return ret;
    }
    return ret + 1;
}

orderedPair makePair(int x, int y)
{
    orderedPair pair;
    pair.x = x;
    pair.y = y;
    return pair;
}

bignum bignum_pow(int base, int exp)
{
    bignum ret, tmp, bignum_base;
    int_to_bignum(base, &tmp);
    int_to_bignum(base, &bignum_base);
    for (int i = 1; i < exp; i++)
    {
        multiply_bignum(&tmp, &bignum_base, &ret);
        copy_bignum(&ret, &tmp);
    }
    return ret;
}

void choose(int x, int y, bignum* ret)
{
    bignum numerator, prod_denominator, fac_y, denominator; 
    int_to_bignum(1, &numerator);
    int_to_bignum(1, &denominator);
    int_to_bignum(1, &prod_denominator);
    int_to_bignum(1, &fac_y);
    factorial(x, &numerator);
    factorial(x - y, &denominator);
    factorial(y, &fac_y);
    multiply_bignum(&fac_y, &denominator, &prod_denominator);
    divide_bignum(&numerator, &prod_denominator, ret);
}

void factorial(int x, bignum* ret)
{
    bignum multiplier, tmp;
    int_to_bignum(1, &tmp);
    for (int i = 1; i <= x; i++)
    {
        int_to_bignum(i, &multiplier);
        multiply_bignum(&tmp, &multiplier, ret);
        copy_bignum(ret, &tmp);
    }
}

int *arrCopy(int *toCopy, int size)
{
    int *ret = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        ret[i] = toCopy[i];
    }
    return ret;
}

void bignumIntAdd(int i, int j, bignum *c)
{
    bignum a, b;
    int_to_bignum(i, &a);
    int_to_bignum(j, &b);
    add_bignum(&a, &b, c);
}

void bignumIntSubtract(int i, int j, bignum *c)
{
    bignum a, b;
    int_to_bignum(i, &a);
    int_to_bignum(j, &b);
    subtract_bignum(&a, &b, c);
}

void bignumIntMultiply(int i, int j, bignum *c)
{
    bignum a, b;
    int_to_bignum(i, &a);
    int_to_bignum(j, &b);
    multiply_bignum(&a, &b, c);
}

void bignumIntDivide(int i, int j, bignum *c)
{
    bignum a, b;
    int_to_bignum(i, &a);
    int_to_bignum(j, &b);
    divide_bignum(&a, &b, c);
}