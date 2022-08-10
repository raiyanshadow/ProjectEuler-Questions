// Smallest multiple

#include "essentials.c"

int main()
{
    int divisibleMax;
    int check;
    scanf("%i", &divisibleMax);

    timeStart();

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

    timeEnd();
    return 0;
}
