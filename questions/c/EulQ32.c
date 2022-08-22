// Pandigital products

#include "essentials.c"

#define SIZE 10

int check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int isInUnique(long long i, long long j, long long prod);

int main()
{
    timeStart();
    long long ret = 0;
    int size = 1;
    long long *unusuals = (long long *) calloc(size, sizeof(long long));
    for (long long i = 1; i < 9999; i++)
    {
        for (long long j = 1; j < 9999; j++)
        {
            long long prod = i * j;
            int ilen = floor(log10(i)) + 1;
            int jlen = floor(log10(j)) + 1;
            int prodlen = floor(log10(prod)) + 1;
            if (ilen + jlen + prodlen > SIZE)
            {
                break;
            }
            if (isInUnique(i, j, prod) == 0)
            {
                if (seenIn(prod, unusuals, size) == 0)
                {
                    unusuals = (long long *) realloc(unusuals, size * sizeof(long long));
                    unusuals[size - 1] = prod;
                    size++;
                }
            }
            for (int i = 0; i < SIZE; i++)
            {
                check[i] = 0;
            }
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        ret += unusuals[i];
    }

    free(unusuals);

    printf("%lli\n", ret);
    timeEnd();
}

int isInUnique(long long i, long long j, long long prod)
{
    int ilen = floor(log10(i)) + 1;
    int jlen = floor(log10(j)) + 1;
    int prodlen = floor(log10(prod)) + 1;
    for (int m = ilen - 1; m >= 0; m--)
    {
        check[(i % 10)]++;
        i /= 10;
    }
    for (int m = jlen - 1; m >= 0; m--)
    {
        check[(j % 10)]++;
        j /= 10;
    }
    for (int m = prodlen - 1; m >= 0; m--)
    {
        check[(prod % 10)]++;
        prod /= 10;
    }
    if (check[0] != 0)
    {
        return 1;
    }
    for (int m = 1; m < SIZE; m++)
    {
        if (check[m] == 0 || check[m] > 1)
        {
            return 1;
        }
    }
    return 0;
}
