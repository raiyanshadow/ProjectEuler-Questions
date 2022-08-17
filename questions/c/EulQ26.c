// Reciprocal cycles

#include "essentials.c"

int recurrenceLength(int denom);
int findHighestRepeating(int upTo);

int main()
{
    int upTo;
    scanf("%i", &upTo);

    timeStart();

    int highest = findHighestRepeating(upTo);
    printf("%i\n", highest);

    timeEnd();
}

int recurrenceLength(int denom)
{
    if (denom % 2 == 0 || denom % 5 == 0)
    {
        return 0;
    }
    int a = 1;
    int t = 0;
    do 
    {
        // multplicative order
        a = (a * 10) % denom;
        t++;
    } while (a != 1);
    return t;
}

int findHighestRepeating(int upTo)
{
    int ret = 0;
    int tmp = 0;
    for (int i = 2; i < upTo; i++)
    {
        int n = recurrenceLength(i);
        if (n > tmp)
        {
            ret = i;
            tmp = n;
        }
    }
    return ret;
}