// Even Fibonacci numbers


#include <stdio.h>
#include <time.h>

long int even_fib_sum(long int max);

int main(void)
{
    float startTime = (float) clock () / CLOCKS_PER_SEC;
    
    printf("Input positive integer: ");
    long int a; scanf("%li", &a);
    
    printf("Sum of all even Fibonacci numbers under %li is %li\n", a, even_fib_sum(a));
    
    float endTime = (float) clock () / CLOCKS_PER_SEC;
    
    float timeElapsed = endTime - startTime;
    printf("\nTime: %f", timeElapsed);
}

long int even_fib_sum(long int max)
{
    long int lastTerm = 1;
    long int currentTerm = 1;
    long int theoryTerm = 1;
    long int sum = 0;
    
    while (currentTerm < max)
    {
        if ((currentTerm + lastTerm) % 2 == 0)
        {
            sum += currentTerm + lastTerm;
        }
        theoryTerm = lastTerm;
        lastTerm = currentTerm;
        currentTerm += theoryTerm;
    }
    
    return sum;
}