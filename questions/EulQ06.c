// Sum square difference

#include "essentials.c"

int main()
{
    int x;
    scanf("%i", &x);

    timeStart();

    long long squareOfSum = pow((x * (x + 1)) / 2, 2);                // sum of n numbers formula then squared
    long long sumOfSquares = (x * (x + 1) * (2 * x + 1)) / 6;         // sum of n^2 numbers formula
    long long diff = squareOfSum - sumOfSquares;

    printf("%lli\n", diff);

    timeEnd();
    return 0;
}
