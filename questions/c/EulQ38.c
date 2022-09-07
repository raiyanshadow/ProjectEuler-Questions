// Pandigital multiples

#include "essentials.c"

int check[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

bool isPandigital(long long x);

int main()
{
    timeStart();

    /* 
       number must start with 9 in order to be largest
       starting number cant be 2 digits long, then n = 3 gives an 8 digit number and n = 4 gives an 11 digit number
       starting number cant be 3 digits long either
       starting number must be 4 digits, meaning n = 2
       understand that if the 2nd digit > 4, then a 1 gets carried over, which we dont want
       so our max value should be 9487
       the minimum is 9213 since 9123 does not result in a 9 digit number
    */ 
    for (int i = 9487; i >= 9213; i--)
    {
        long long ret = 100000*i + 2*i;
        if (isPandigital(ret))
        {
            printf("%lli\n", ret);
            timeEnd();
            return 0;
        }
        for (int i = 1; i < 10; i++)
        {
            check[i] = 0;
        }
    }
    
    timeEnd();
}

bool isPandigital(long long x)
{
    long long copy = x;
    while (copy != 0)
    {
        check[(copy % 10)]++;
        copy /= 10;
    }

    for (int i = 1; i < 10; i++)
    {
        if (check[i] != 1)
        {
            return false;
        }
    }

    return true;
}
