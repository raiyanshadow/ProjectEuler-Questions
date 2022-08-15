// Largest Collatz sequence

#include "essentials.c"

void largestCollatz(long long max);

int main()
{
    long long max;
    scanf("%lli", &max);
    timeStart();

    largestCollatz(max);

    timeEnd();
}

void largestCollatz(long long max)
{
    long long maxLen = 0, maxNum = 0;
    for (long long i = 1; i < max; i++)
    {
        long long curLen = 0;
        long long tmp = i;
        do 
        {
            if (tmp % 2 == 0)
            {
                tmp /= 2;
            }
            else
            {
                tmp = (3 * tmp) + 1;
            }
            curLen++;
        } while (tmp != 1);
        maxNum = (MAX(maxLen, curLen) == curLen) ? i : maxNum; 
        maxLen = MAX(maxLen, curLen);
    }

    printf("%lli\n", maxNum);
}