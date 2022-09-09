// Pandigital Primes

/* 
   we must understand that a number is divisible by 3 iff the sum of its digit is also divisible by 3
   so, 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45 % 3 == 0
   1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36 % 3 == 0
   1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 % 3 != 0
   so the upper limit should be a 7 digit number, and the highest is: 7654321
*/

#include "essentials.c"

#define MAX 7654321

int main()
{
    timeStart();

    for (long long i = MAX; i >= 1; i--)
    {
        if (i % 10 == 2 || i % 10 == 5)
        {
            continue;
        }
        int digitLen = noDigits(i);
        if (isPandigital(i, digitLen))
        {
            if (isPrime(i))
            {
                printf("%lli\n", i);
                timeEnd();
                return 0;
            }
        }
    }
}