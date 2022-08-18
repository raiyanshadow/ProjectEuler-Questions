// Distinct powers

#include "essentials.c"

int bignumSeenIn(bignum val, bignum *bignumarr, int size);

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    timeStart();

    bignum *powers = malloc(sizeof(bignum));
    int term = 1;

    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            bignum result = bignum_pow(i, j);

            if (!bignumSeenIn(result, powers, term))
            {
                powers[term - 1] = result;
                term++;
                powers = (bignum *) realloc(powers, term * sizeof(bignum));
            }
        }
    }

    printf("%i\n", term - 1);
    free(powers);
    timeEnd();
}

int bignumSeenIn(bignum val, bignum *bignumarr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (compare_bignum(&val, &bignumarr[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}