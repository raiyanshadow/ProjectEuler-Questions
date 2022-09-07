// Truncatable primes

#include "essentials.c"

// note that the right most digit must end with 3 or 7. If it ends with any other number, the truncatable number will not be prime.
// if it ends with a 2, it is even, not prime
// if it ends with a 5, it is divisible by 5, not prime
int singleDigitPrimesRight[] = { 3, 7 };

// note that the leftmost digit must begin with 2, 3, 5, or 7. If it starts with any other number, the truncatable number will not be prime.
int singleDigitPrimesLeft[] = { 2, 3, 5, 7 };

bool truncatableFromLeft(long long num, int numLen);
bool truncatableFromRight(long long num);
bool primeInFirstAndLast(long long num, int numLen);

int main()
{
    timeStart();
    long long ret = 0;
    int count = 0;
    for (long long i = 11; count < 11; i++)
    {
        if (isPrime(i))
        {
            int numLen = floor(log10(i));
            if (primeInFirstAndLast(i, numLen))
            {
                if (truncatableFromLeft(i, numLen) && truncatableFromRight(i))
                {
                    count++;
                    printf("found: %lli\n", i);
                    ret += i;
                }
            }
        }
    }

    printf("%lli\n", ret);

    timeEnd();
}

bool truncatableFromLeft(long long num, int numLen)
{   
    long long copy = num;
    while (copy)
    {
        copy %= (int)pow(10, numLen);
        numLen--;
        if (isPrime(copy))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool truncatableFromRight(long long num)
{
    long long copy = num;
    while (copy)
    {
        copy /= 10;
        if (isPrime(copy))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool primeInFirstAndLast(long long num, int numLen)
{
    int first = num / (int)pow(10, numLen);
    int last = num % 10;
    
    for (int i = 0; i < 4; i++)
    {
        if (first == singleDigitPrimesLeft[i])
        {
            for (int j = 0; j < 2; j++)
            {
                if (last == singleDigitPrimesRight[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}