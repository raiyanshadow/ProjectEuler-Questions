// Largest product in a series

#include "essentials.c"

#define LENMAX 128

int *strToIntArr(char *c);
void findHighestAdjacentProduct(int *arr, int adj, int size);

int main()
{
    int adjacentDigits;
    scanf("%i", &adjacentDigits);
    char *str;
    scanf("%as", &str);

    timeStart();

    int *digits = strToIntArr(str);
    findHighestAdjacentProduct(digits, adjacentDigits, strlen(str));

    timeEnd();
    free(digits);
    return 0;
}

int *strToIntArr(char *c)
{
    int size = strlen(c);
    int *ret = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        ret[i] = c[i] - 48;
    }

    return ret;
}

void findHighestAdjacentProduct(int *arr, int adj, int size)
{
    long long ret = 0, tmp = 1;
    for (int i = 0; i < size - adj; i++)
    {
        for (int j = 0; j < adj; j++)
        {
            tmp *= arr[i + j];
        }
        ret = ret > tmp ? ret : tmp;
        tmp = 1;
    }

    printf("%lli\n", ret);
}