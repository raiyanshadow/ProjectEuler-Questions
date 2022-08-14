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

int getLineLength(char *fname, char sep)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int ret = 0;
    char tmpsep = sep;

    while (ch != '\n')
    {
        ch = fgetc(f);
        if (tmpsep == 0)
        {
            sep = ch;
        }
        if (ch == sep && ch != '\n')
        {
            ret++;
        }
    }

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
