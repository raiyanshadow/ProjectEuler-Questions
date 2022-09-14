// Amicable numbers

#include "essentials.c"

int amicableSum(int upTo);
int intSeenIn(int val, int *arr, int size);

int main()
{   
    int upTo;
    scanf("%i", &upTo);

    timeStart();

    int sum = amicableSum(upTo);
    printf("%i\n", sum);

    timeEnd();
}

int amicableSum(int upTo)
{
    int ret = 0;
    int *seen = (int *) calloc(1, sizeof(int));
    int size = 0;
    for (int i = 2; i < upTo; i++)
    {
        if (intSeenIn(i, seen, size))
        {
            continue;
        }
        int properSum = 0;
        // optimize so it only searches through prime factors
        // other factor can be gotten by dividing the number by the prime factors
        for (int j = 1; j < sqrt(i); j++)
        {
            if (i % j == 0)
            {
                properSum += j;
                // do not add the number itself
                // also dont add the other factor if its a perfect square
                if (j != 1 && i / j != j)
                {
                    properSum += i / j;
                }
            }
        }
        int tmp = 0;
        for (int j = 1; j < sqrt(properSum); j++)
        {
            if (properSum % j == 0)
            {
                tmp += j;
                if (j != 1 && i / j != j)
                {
                    tmp += properSum / j;
                }
            }
        }
        if (tmp == i && tmp != properSum)
        {
            ret += properSum + i;
            size++;
            seen = (int *) realloc(seen, size * sizeof(int));
            seen[size - 1] = properSum;
        }
    }

    free(seen);

    return ret;
}

int intSeenIn(int val, int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (val == arr[i])
        {
            return 1;
        }
    }

    return 0;
}