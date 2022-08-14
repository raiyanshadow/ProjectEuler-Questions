// 10001st Prime

#include "essentials.c"

void findPrime(int upperBound);

int main()
{
    int x;
    scanf("%i", &x);

    timeStart();

    findPrime(x);

    timeEnd();
    return 0;
}

void findPrime(int upperBound)
{
    long long ret = 2;
    while (upperBound > 0)
    {
        if (isPrime(ret))
        {
            upperBound--;
            if (upperBound == 0)
            {
                printf("%lli\n", ret);
            }
        }
        ret++;
    }
    return;
}
