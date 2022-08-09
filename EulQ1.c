// Multiples of 3 and 5

#include <stdio.h>
#include <time.h>

long int mult(long int max);

int main ()
{
    float startTime = (float) clock () / CLOCKS_PER_SEC;

    printf("Enter a positive integer: ");
    long int a; scanf("%li", &a);
    
    printf("Sum of all multiples under %li is %li", a, mult(a));

    float endTime = (float) clock () / CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    printf ("\n Time: %f", timeElapsed);

    return 0;
}

long int mult(long int max)
{
    long int sum = 0;
    for (long int i = 0; i < max; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}