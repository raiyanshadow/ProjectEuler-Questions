// Largest prime factor

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 

int main(void)
{
    long long x;
    scanf("%lli", &x);

    float timeStart = (float) clock () / CLOCKS_PER_SEC;

    long long largestPrime;

    while (x % 2 == 0)
    {
        largestPrime = 2;
        x /= 2;
    }

    // every composite number has a prime factor less than or equal to its square root
    for (int i = 3; i <= sqrt(x); i += 2)
    {
        while (x % i == 0)
        {
            largestPrime = i;
            x /= i;
        }
    }

    if (x > 2)
    {
        printf("%lli\n", x);
    }

    printf("%lli\n", largestPrime);

    float timeEnd = (float) clock () / CLOCKS_PER_SEC;
    float timeElapsed = timeEnd - timeStart;
    printf("Time elapsed: %f\n", timeElapsed);
}