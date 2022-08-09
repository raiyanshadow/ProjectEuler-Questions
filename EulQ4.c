// Largest Palindrome Product

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void largestPalindrome(int digits);
bool isPalindrome(long long x);

int main()
{
    int numDigits;
    scanf("%i", &numDigits);

    float timeStart = (float) clock () / CLOCKS_PER_SEC;

    largestPalindrome(numDigits);

    float timeEnd = (float) clock () / CLOCKS_PER_SEC;
    float timeElapsed = timeEnd - timeStart;
    printf("Time elapsed: %f", timeElapsed);
}

void largestPalindrome(int digits)
{
    if (digits < 2)
    {
        return;
    }

    int min = pow(10, digits - 1);
    int max = pow(10, digits);
    int prod, ret = 0;

    for (int i = max - 1; i >= min; i--)
    {
        for (int j = max - 1; j >= i; j--)
        {
            prod = i * j;
            if (prod > ret && isPalindrome(prod) == true)
            {
                ret = prod;
            }
        }
    }

    printf("%i\n", ret);
    return;
}

bool isPalindrome(long long int x)
{
    int copy = 0, tmpcopy = x;
    while (x != 0)
    {
        copy = copy * 10 + x % 10;
        x /= 10;
    }

    return (tmpcopy == copy);
}