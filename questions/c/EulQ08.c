// Largest product in a series

#include "essentials.c"

#define LENMAX 128

int *strToIntArr(char *fname, int size);
void findHighestAdjacentProduct(int *arr, int adj, int size);

int main()
{
    int adjacentDigits;
    scanf("%i", &adjacentDigits);

    timeStart();

    int len = getLineLength("../../../testcases/EulQ08.txt", 0, 1);
    int *digits = strToIntArr("../../../testcases/EulQ08.txt", len);
    findHighestAdjacentProduct(digits, adjacentDigits, len);

    timeEnd();
    free(digits);
    return 0;
}

int *strToIntArr(char *fname, int size)
{
    int *ret = malloc(size * sizeof(int));
    FILE *f = fopen(fname, "r");
    int ch = 0, i = 0;

    while (ch != EOF)
    {
        ch = fgetc(f);
        ret[i] = ch - 48;
        i++;
    }

    fclose(f);
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
