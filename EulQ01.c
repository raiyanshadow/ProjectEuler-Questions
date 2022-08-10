// Multiples of 3 and 5

#include "essentials.c"

long long mult(long long max);

int main ()
{
    printf("Enter a positive integer: ");
    long long a; scanf("%lli", &a);

    timeStart();
    
    printf("Sum of all multiples under %lli is %lli\n", a, mult(a));

    timeEnd();

    return 0;
}

long long mult(long long max)
{
    long long sum = 0;
    for (long long i = 0; i < max; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}
