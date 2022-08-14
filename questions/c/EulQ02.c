// Even Fibonacci numbers

#include "essentials.c"

long int even_fib_sum(long int max);

int main(void)
{
    printf("Input positive integer: ");
    long int a; scanf("%li", &a);

    timeStart();
    
    printf("Sum of all even Fibonacci numbers under %li is %li\n", a, even_fib_sum(a));
    
    timeEnd();
    return 0;
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
