// 1000-digit Fibonacci number

#include "essentials.c"

int fibonacciFirstOccurence(int max);

int main()
{
    int maxDigits;
    scanf("%i", &maxDigits);
    timeStart();

    int firstOccurence = fibonacciFirstOccurence(maxDigits);
    printf("%i\n", firstOccurence);

    timeEnd();
}

int fibonacciFirstOccurence(int max)
{
    if (max < 2)
    {
        return 1;
    }
    // using Binet's formula
    double phi = (1 + sqrt(5)) / 2;
    int n = 0, i = 1;
    int digits = 0;
    while (digits < max) 
    {
        digits = (int)ceil((i * log10(phi)) - (log10(5) / 2));
        if (digits >= max)
        {
            n = i;
        }
        i++;
    }

    return n;
}