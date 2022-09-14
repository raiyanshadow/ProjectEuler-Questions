// Goldbach's other conjecture

#include "essentials.c"

unsigned long long findAnomaly();

int main()
{
    timeStart();

    printf("%lli\n", findAnomaly());

    timeEnd();
}

unsigned long long findAnomaly()
{
    
    for (unsigned long long i = 9; ; i++)
    {
        bool is = false;
        if (i % 2 == 0)
        {
            continue;
        }
        else
        {
            if (isPrime(i) == 0)
            {
                for (unsigned long long j = 2; j < i; j++)
                {
                    if (isPrime(j))
                    {
                        long long kmax = (unsigned long long)sqrt((i-j)/2);
                        for (unsigned long long k = 1; k <= kmax; k++)
                        {
                            unsigned long long formula = j + (2*(k*k));
                            if (formula == i)
                            {
                                is = true;
                                break;
                            }
                        }
                    }
                    if (is)
                    {
                        break;
                    }
                }
                if (!is)
                {
                    return i;
                }
            }
        }
    }
}