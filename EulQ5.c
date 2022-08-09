// Smallest multiple

#include <stdio.h>
#include <time.h>

int main()
{
    float timeStart = (float) clock () / CLOCKS_PER_SEC;

    int divisibleMax;
    int check;
    scanf("%i", &divisibleMax);

    for (int i = divisibleMax; 1 == 1; i++)
    {
        if (check == 1)
        {
            break;
        }
        check = 1;
        for (int j = 2; j <= divisibleMax; j++)
        {
            if (check == 1)
            {
                if (i % j == 0)
                {
                    check = 1;
                    if (j == divisibleMax)
                    {
                        printf("%i\n", i);
                    }
                }
                else
                {
                    check = 0;
                }
            }
            else
            {
                break;
            }
        }
    }

    float timeEnd = (float) clock () / CLOCKS_PER_SEC;
    printf("Time elapsed: %f", timeEnd-timeStart);
}