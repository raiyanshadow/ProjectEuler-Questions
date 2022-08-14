// Highly divisble triangular numbers

#include "essentials.c"

long long findNum(int minDivisors);
long long triangleNumber(long long n);
long long findFactors(long long n);

int main()
{
    int divisors;
    scanf("%i", &divisors);

    timeStart();

    long long triangleNumber = findNum(divisors);
    printf("%lli\n", triangleNumber);

    timeEnd();
}

long long findNum(int minDivisors)
{
    long long primeFactorsPowerProd = 0;

    for (long long i = 1; ; i++)                      // i = base value for triangular series
    {
        long long tmp = (i * (i + 1)) / 2;            // triangular number formula is just the formula for sum of all natural numbers up to i: n * (n + 1) / 2, where n is in the set of all natural numbers
        primeFactorsPowerProd = findFactors(tmp);     // returns number of factors for the triangular number
        if (primeFactorsPowerProd > minDivisors)
        {
            return tmp;                               // return value when a number has more than the specified factors asked for
        }
    }
}

long long triangleNumber(long long n)
{
    return (n * (n + 1)) / 2;
}

long long findFactors(long long n)
{
    if (isPrime(n) == 2)      // meaning that n = 1
    {
        return 1;             // 1 is not prime or divisible, so it has only 1 factor: 1
    }
    if (isPrime(n) == 1)      // meaning that n is prime
    {
        return 2;             // prime numbers have only 2 factors: itself and 1
    }

    /*
        Step 1: Prime Factorization
            - Find all prime factors, and assert them into an "array" (pointer, whatever)
        Step 2: Use nice formula to calculate the number of factors for the number using prime factors
            - Given an array consisting of the prime factors of a number, get common numbers and add them by increasing their exponent: A, A = A^2
            - Array will be pre-sorted so no need for any sorting algorithms (nice)
            - Use formula to find number of factors
                - Given an assortment: a^x, b^y, c^z, ...
                - Consider exponents: N = (x + 1) * (y + 1) * (z + 1) * ... 
                    - where N is the number of factors
            - Return N
    */

    long long *primeFactors = (long long*)calloc(1, sizeof(long long));                                 // pointer to store factors
    long long previous = n;                                     
    int max = 0;                                                                                        // tracks size of pointer
                        
    while (isPrime(n) == 0)                                                                             // while n is not prime, so stop when n becomes prime
    {                       
        for (long long i = 2; i <= sqrt(n); i++)                                                        // go through all possible prime factors up to sqrt(n), since prime factors are always less than or equal to sqrt(n)
        {
            if (isPrime(i))                                                                             // check if i is prime
            {
                if (n % i == 0)                                                                         // check if n is divisble by i
                {
                    primeFactors[max] = i;                                                              // if yes, then that is one of the prime factors
                    max++;
                    primeFactors = (long long*)realloc(primeFactors, (max + 1) * sizeof(long long));
                    previous = n;
                    n /= i;                                                                             // divide n by i and continue to find more prime factors
                    break;                                                                              // break since we found a prime factor already
                }
            }
        }
    } 

    primeFactors[max] = n;                                                      // extra containment to store the last prime factor, since n will eventually become a prime when getting divided
    max++;

    int reps = 0;                                                               // track number of number repitions
    long long ret = 1;                                                          // return value

    for (int i = 0; i < max; )
    {
        long long cur = primeFactors[i];                                        // store current value that we are checking for any duplicates

        if (i == max - 1)                                                       // if we are at the last index position, then there cannot be any duplicates of that number
        {
            ret *= 2 + reps;
            i++;
            break;
        }

        for (int j = (i + 1); j < max + 1; j++)                                 // j will look at the value at primeFactors[i + 1], so the very next position
        {
            if (cur == primeFactors[j])                                         // found duplicate
            {
                reps++;
                primeFactors[j] = 0;
            }
            else                                                                // different number
            {   
                i = j;                                                          // set i to the current position
                break;                                                          // break loop to reset duplicate checking
            }
        }
        ret *= 2 + reps;                                                        // having 0 = reps means that there were no repeats, more than 1 means there were reps duplicates, this is our factor formula
        reps = 0;                                                               // reset duplicate count
    }

    free(primeFactors);

    return ret;
}
