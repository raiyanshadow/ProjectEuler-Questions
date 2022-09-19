// Consecutive prime sum

#include "essentials.c"

int main()
{
    int under;
    scanf("%i", &under);
    timeStart();

    long long ret, lastPrime = 0;
    int i = 2;
    long long max = (long long)pow(10, under);
    while (ret < max)
    {
        if (isPrime(i))
        {
            lastPrime = i;
            ret += i;
        }
        i++;
    }

    ret -= lastPrime; // this is to correct the number since the while loop goes over 1 million for one iteration

    for (int i1 = 2; i1 < lastPrime; i1++)
    {
        if (isPrime(ret))
        {
            printf("%lli\n", ret);
            break;
        }
        if (isPrime(i1))
        {
            ret -= i1;
        }
    }

    timeEnd();
}