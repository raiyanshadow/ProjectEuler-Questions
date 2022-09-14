// Distinct prime factors

// was stuck on this for a bit, due to c memory management issues :p

#include "essentials.c"

int primeFactorize(long long n);
long long findDistinctConsecutive(int n);
int distinctArrLen(long long *arr, int size);

int main()
{
    timeStart();

    printf("%lli\n", findDistinctConsecutive(5));

    timeEnd();
}

long long findDistinctConsecutive(int n)
{
    for (int i = 10; ; i++)
    {
        bool check = false;
        int distinct = primeFactorize(i);  
        if (distinct != n)
        {
            continue;
        }

        else {
            for (int j = i + 1; j < i + n; j++)
            {
                distinct = primeFactorize(j);
                if (distinct == n)
                {
                    check = true;
                }
                else
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                return i;
            }
        }
    }
}

int distinctArrLen(long long *arr, int size)
{
    int ret = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i-1])
        {
            ret++;
        }
    }
    return ret + 1;
}

int primeFactorize(long long n)
{          
    // Prime factorization algorithm gotten from question 12  
    long long *primeFactors = (long long*)calloc(1, sizeof(long long));                       
    int max = 0;                                                                                        
                        
    while (isPrime(n) == 0)                                                                             
    {                       
        for (long long i = 2; i <= sqrt(n); i++)                                                       
        {
            if (isPrime(i))                                                                             
            {
                if (n % i == 0)
                {
                    primeFactors[max] = i;                                                              
                    max++;
                    primeFactors = realloc(primeFactors, (max + 1) * sizeof(long long));
                    n /= i;                                                                             
                    break;                                                                              
                }
            }
        }
    } 

    primeFactors[max] = n;                                                      
    max++;

    int ret = distinctArrLen(primeFactors, max);
    free(primeFactors);
    return ret;
}