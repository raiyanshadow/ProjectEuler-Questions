// Digit cancelling fractions

#include "essentials.c"

#define DIGITS 2

orderedPair removeCommon(int a, int b);
bool simplifyUntil(int a, int b, orderedPair cmp);
void simplify(orderedPair* original);
bool isTrivial(orderedPair trivial);

int main()
{
    timeStart();
    orderedPair final = makePair(1, 1);
    for (int i = 10; i < 100; i++)
    {
        for (int j = 10; j < i; j++)
        {
            orderedPair commonCancel = removeCommon(j, i);
            orderedPair frac = makePair(j, i);
            if (simplifyUntil(j, i, commonCancel) && !equalPairs(commonCancel, frac) && !isTrivial(frac))
            {
                final.x *= j;
                final.y *= i;
            }
        }
    }
    simplify(&final);
    printf("%i\n", final.y);
    timeEnd();
}

orderedPair removeCommon(int a, int b)
{
    orderedPair ret = makePair(a, b);
    for (int i = DIGITS - 1; i >= 0; i--)
    {
        int icmp = (a / (int)pow(10, i)) % 10;
        for (int j = DIGITS - 1; j >= 0; j--)
        {
            int jcmp = (b / (int)pow(10, j)) % 10;
            if (icmp == jcmp)
            {
                for (int k = DIGITS - 1; k >= 0; k--)
                {
                    int aTmp = (a / (int)pow(10, k)) % 10;
                    int bTmp = (b / (int)pow(10, k)) % 10;
                    if (aTmp != icmp)
                    {
                        ret.x = aTmp;
                    }
                    if (bTmp != jcmp)
                    {
                        ret.y = bTmp;
                    }
                } 
            }
        }
    }
    return ret;
}

bool simplifyUntil(int a, int b, orderedPair cmp)
{   
    orderedPair copy = makePair(cmp.x, cmp.y);
    simplify(&copy);
    for (int i = 2; i <= MIN(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            orderedPair tmp = makePair(a / i, b / i);
            simplify(&tmp);
            if (equalPairs(tmp, copy))
            {
                return true;
            }
        }
    }
    return false;
}

void simplify(orderedPair* original)
{
    if (isPrime(original->x) && isPrime(original->y))
    {
        return;
    }

    for (int i = 2; i <= MIN(original->x, original->y); i++)
    {
        if (original->x % i == 0 && original->y % i == 0)
        {
            original->x /= i;
            original->y /= i;
            simplify(original);
        }
    }
}

bool isTrivial(orderedPair trivial)
{
    if (trivial.x % 10 == 0 || trivial.y == 0)
    {
        return true;
    }
    return false;
}