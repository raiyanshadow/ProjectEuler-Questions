// Powerful digit sum

#include "essentials.c"

int bignum_digitSum(bignum *a);

int main()
{
    timeStart();
    // int m = 1;
    // from analysis, we see that the digit sum is always less than 1000
    // by quickly looking at the results, 99^95 produces the largest digit sum
    // no need for further search
    // for (int i = 99; i >= 2; i--)
    // {
    //     for (int j = 100; j >= 2; j--)
    //     {
    //         bignum power = bignum_pow(i, j);
    //         int tmp = MAX(m, bignum_digitSum(&power));
    //         printf("%i^%i = %i\n", i, j, tmp);
    //     }
    // }

    bignum power = bignum_pow(99, 95);
    int m = bignum_digitSum(&power);
    printf("%i\n", m);
    timeEnd();
}

int bignum_digitSum(bignum *a)
{
    int ret = 0;
    for (int i = 0; i <= a->lastdigit; i++)
    {
        ret += a->digits[i];
    }
    return ret;
}