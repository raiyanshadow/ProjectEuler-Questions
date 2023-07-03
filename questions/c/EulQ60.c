// Prime pair sets
// not as hard as i thought...

#include "essentials.c"

#define SIZE 5

bool checkSet(long long *set, int n);
long long combine(long long a, long long b);

int main()
{
    timeStart();
    long long *primes = malloc(sizeof(long long));
    int len = sieve(&primes, 10000);
    long long *set = malloc(5 * sizeof(long long));
    long long ret = 0;
    for (int j = 1; j < len; j++)
    {
        set[0] = primes[j];
        bool flag = false;
        for (int i = 1, a = j; i < 5; i++, a++)
        {
            if (a > len-i-1)
            {
                if (i == 1)
                {
                    break;
                }
                a = posSeenIn(set[i-1], primes, len);
                set[i-1] = primes[a];
                set = realloc(set, i*sizeof(long long));
                i -= 2;
                continue;
            }
            set = realloc(set, (i + 1)*sizeof(long long));
            set[i] = primes[a];
            if (i == 0)
            {
                continue;
            }
            if (checkSet(set, i+1))
            {
                if (i == 4)
                {
                    flag = true;
                    break;
                }
                continue;
            }
            i--;
        }
        if (flag)
        {
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        ret += set[i];
    }
    printf("%lli\n", ret);
    free(set);
    free(primes);
    timeEnd();
}

bool checkSet(long long *set, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (set[i] < 0)
        {
            return false;
        }
    }
    bool flag = true;
    for (int i = 0; i < n-1; i++)
    {
        long long a = combine(set[i], set[n-1]);
        long long b = combine(set[n-1], set[i]);
        if (isPrime(a))
        {
            if (isPrime(b))
            {
                continue;
            }
            return false;
        }
        return false;
    }
    return true;
}

long long combine(long long a, long long b)
{
    int alen = noDigits(a);
    int Flen = alen + noDigits(b);
    return (a*(int)pow(10, (Flen-alen))) + b;
}