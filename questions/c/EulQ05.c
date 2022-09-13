// Smallest multiple

// Took ~4 seconds before, but now it takes ~0.0 ms
// Original:
/*
int main()
{
    int divisibleMax;
    int check;
    scanf("%i", &divisibleMax);

    timeStart();

    for (long long i = divisibleMax; 1 == 1; i++)
    {
        if (check == 1)
        {
            break;
        }
        check = 1;
        for (int j = 2; j <= divisibleMax; j++)
        {
            if (check == 1)
            {
                if (i % j == 0)
                {
                    check = 1;
                    if (j == divisibleMax)
                    {
                        printf("%lli\n", i);
                    }
                }
                else
                {
                    check = 0;
                }
            }
            else
            {
                break;
            }
        }
    }

    timeEnd();
    return 0;
}
*/

#include "essentials.c"

long long gcd(long long x1, long long x2);

int main()
{
    int divisibleMax;
    long long ret = 1;
    scanf("%i", &divisibleMax);

    timeStart();

    for (int i = 2; i <= divisibleMax; i++)
    {
        ret = (ret * i)/gcd(ret, i);
    }
    printf("%lli\n", ret);

    timeEnd();
    return 0;
}

long long gcd(long long x1, long long x2)
{
    if (x2 != 0)
    {
        return gcd(x2, x1 % x2);
    }
    else
    {
        return x1;
    }
}