// Summation of primes

#include "essentials.c"

long long primeSums(long long x);
int isPrime(long long x);

int main()
{
    long long x;
    scanf("%lli", &x);

    timeStart();

    long long sum = primeSums(x);
    printf("%lli\n", sum);

    timeEnd();
}

long long primeSums(long long x)
{
    long long ret = 0;
    for (long long i = 2; i < x; i++)
    {
        if (isPrime(i))
        {
            ret += i;
        }
    }

    return ret;
}