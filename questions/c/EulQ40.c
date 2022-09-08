// Champernowne's constant

#include "essentials.c"

int checkpoints[] = {1, 10, 100, 1000, 10000, 100000, 1000000}; 

int main()
{
    timeStart();

    int ret = 1;
    int goal = 0;
    int pos = 1;
    for (int i = 1; goal < 7; i++)
    {
        int digits = floor(log10(i)) + 1;
        for (int j = 1; j <= digits; j++, pos++)
        {
            if (pos == checkpoints[goal])
            {
                ret *= i / (int)pow(10, digits - j) % 10;
                goal++;
            }
        }
    }

    printf("%i\n", ret);

    timeEnd();
}