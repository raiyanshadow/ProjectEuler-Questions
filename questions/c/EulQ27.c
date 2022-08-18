// Highest quadratic prime

#include "essentials.c"

long long highestQuadPrime(int a, int b);

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    timeStart();

    long long quadPrime = highestQuadPrime(a, b);
    printf("%lli\n", quadPrime);

    timeEnd();
}

long long highestQuadPrime(int a, int b)
{
    long long ret = 0;
    orderedPair max;
    for (int i = -1 * (a - 1); i < a; i++)
    {
        for (int j = -1 * b; j <= b; j++)
        {
            int n = 0, tmp = 0;
            long long exp = (long long) abs((n * n) + (i * n) + j);
            while (isPrime(exp))
            {
                tmp++;
                n++;
                exp = (long long) abs((n * n) + (i * n) + j);
            }
            if (tmp > ret)
            {
                ret = tmp;
                max.x = i;
                max.y = j;
            }
        }
    }
    return (max.x * max.y);
}