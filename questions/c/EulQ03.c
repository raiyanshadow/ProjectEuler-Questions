// Largest prime factor

#include "essentials.c"

int main(void)
{
    long long x;
    scanf("%lli", &x);

    timeStart();

    long long largestPrime;

    while (x % 2 == 0)
    {
        largestPrime = 2;
        x /= 2;
    }

    // every composite number has a prime factor less than or equal to its square root
    for (int i = 3; i <= sqrt(x); i++)
    {
        if (!isPrime(i))
        {
            continue;
        }
        while (x % i == 0)
        {
            largestPrime = i;
            x /= i;
        }
    }

    printf("%lli\n", x);

    timeEnd();
    return 0;
}
