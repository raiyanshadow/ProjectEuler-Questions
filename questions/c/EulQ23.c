// Non-abundant sums

#include "essentials.c"

#define LIMIT 28123

bool isAbundant(int val);

int main()
{
    timeStart();

    int size = 1;
    int* range = (int *) calloc(size, sizeof(int));

    for (int i = 12; i <= LIMIT; i++)
    {
        if (isAbundant(i))
        {
            range[size - 1] = i;
            size++;
            range = (int *) realloc(range, size * sizeof(int));
        }
    }
    size--;

    int sumsize = 0;
    bool nonAbundantSum[LIMIT + 1] = {false};

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if ((range[i] + range[j]) <= LIMIT)
            {
                nonAbundantSum[(range[i] + range[j])] = true;
            }
        }
    }
    sumsize--;

    long long sum = 0;

    for (int i = 1; i <= LIMIT; i++)
    {
        if (nonAbundantSum[i] == false)
        {
            sum += i;
        }
    }

    printf("%i\n", sum);

    free(range);

    timeEnd();
}

bool isAbundant(int val)
{
    int properSum = 0;
    for (int i = 1; i <= sqrt(val); i++)
    {
        if (val % i == 0)
        {
            properSum += i;
            if (i != 1 && (val / i) != i)
            {
                properSum += (val / i);
            }
        }
    }
    if (properSum > val)
    {
        return true;
    }
    return false;
}
