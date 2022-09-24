// Lychrel Numbers

#include "essentials.c"

int main()
{
    timeStart();

    int count = 0;
    // checking if a number is reverse of a previoulsy discovered
    // lychrel number does not provide any time differences
    for (int i = 1; i <= 10000; i++)
    {
        unsigned long long num = i;
        // 30 max iterations is just enough for long long range
        // and 50 iters not needed for this problem :p
        for (int j = 0; j < 30; j++)
        {
            num = num + reverseNum(num);

            if (isPalindrome(num))
            {
                count++;
                break;
            }
        }
    }

    printf("%i\n", 10000-count);

    timeEnd();
}