// Spiral primes

#include "essentials.c"

int main()
{
    timeStart();
    float prime_ratio = 1.0f;
    long long cur = 1;
    long long step = 2;
    int diagonal_primes = 0;
    int corners = 1;
    int layer = 1;
    while (prime_ratio >= 0.1)
    {
        cur += step;
        for (int i = 0; i < 3; i++)
        {
            if (isPrime(cur))
            {
                diagonal_primes++;
            }
            cur += step;
        }
        step += 2;
        corners += 4;
        prime_ratio = (float)diagonal_primes / (float)corners;
    }
    printf("%lli\n", step-1);
    timeEnd();
}