// Sum square difference

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    float timeStart = (float) clock () / CLOCKS_PER_SEC;

    int x;
    scanf("%i", &x);

    long long squareOfSum = pow((x * (x + 1)) / 2, 2);                // sum of n numbers formula then squared
    long long sumOfSquares = (x * (x + 1) * (2 * x + 1)) / 6;         // sum of n^2 numbers formula
    long long diff = squareOfSum - sumOfSquares;

    printf("%lli\n", diff);

    float timeEnd = (float) clock () / CLOCKS_PER_SEC;
    printf("Time elapsed: %f", timeEnd-timeStart);
}