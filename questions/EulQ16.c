// Power digit sum

#include "essentials.c"

long long digitSum(bignum b);

int main()
{
    int base, exp;
    scanf("%i %i", &base, &exp);
    timeStart();

    bignum big = bignum_pow(base, exp);
    long long x = digitSum(big);
    printf("%lli\n", x);

    timeEnd();
}

long long digitSum(bignum b)
{
    long long ret = 0;
    for (int i = 0; i < MAXDIGITS; i++)
    {   
        ret += b.digits[i];
    }
    return ret;
}
