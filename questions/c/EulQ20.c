// Factorial digit sum

#include "essentials.c"

int factorialSum(bignum b);

int main()
{
    int x;
    scanf("%i", &x);
    timeStart();

    bignum ret;
    initialize_bignum(&ret);
    factorial(x, &ret);
    int sum = factorialSum(ret);
    printf("%i\n", sum);

    timeEnd();
}

int factorialSum(bignum b)
{
    int ret = 0;
    for (int i = 0; i < MAXDIGITS; i++)
    {
        ret += b.digits[i];
    }
    return ret;
}