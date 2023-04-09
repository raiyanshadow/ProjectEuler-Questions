// Large sum

#include "essentials.c"

void readFile(char *fname, int **mat);
void addAllDigits(int **mat, int rows, int cols, long long *ret);
void insertAt(long long *arr, int size, int idx, long long val);
void conclude(long long *arr, int size);
void printUpTo(long long *arr, int upTo);

int main()
{
    int upTo;
    scanf("%i", &upTo);

    timeStart();

    int x = getFileLines("../../testcases/EulQ13.txt");
    int y = getLineLength("../../testcases/EulQ13.txt", 0, 1);

    int **nums = (int **) calloc(x, sizeof(int *));
    for (unsigned int i = 0; i < x; i++)
    {
        nums[i] = (int *) calloc(y, sizeof(int));
    }

    long long *sums = (long long *) calloc(y, sizeof(long long));
    readFile("../../testcases/EulQ13.txt", nums);
    addAllDigits(nums, x, y, sums);

    int re = floor(log10(sums[0])) + 1;
    sums = (long long*) realloc(sums, ((re - 1) + y)*sizeof(long long));

    conclude(sums, y);
    printUpTo(sums, upTo);

    for (int i = 0; i < x; i++)
    {
        free(nums[i]);
    }
    free(nums);
    free(sums);

    timeEnd();
}

void readFile(char *fname, int **mat)
{
    FILE *f = fopen(fname, "r");
    int ch = fgetc(f);
    int i = 0, j = 0;

    while (ch != EOF)
    {
        if (ch == '\n' || ch == EOF)
        {
            j = 0;
            i++;
        }
        else
        {
            *(*(mat + i) + j) = ch - 48;
            j++;
        }
        ch = fgetc(f);
    }

    fclose(f);
}

void addAllDigits(int **mat, int rows, int cols, long long *ret)
{
    long long tmp = 0;
    for (int i = cols - 1; i >= 0; i--)
    {
        for (int j = 0; j < rows; j++)
        {
            tmp += mat[j][i];
        }
        if (tmp >= 10 && i != 0)
        {
            *(ret + i) = tmp % 10;
            tmp /= 10;
            continue;
        }
        *(ret + i) = tmp;
        tmp = 0;
    }
}

void insertAt(long long *arr, int size, int idx, long long val)
{
    for (int i = size; i > idx; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + idx) = val;
}

void conclude(long long *arr, int size)
{
    while (*arr >= 10)
    {
        insertAt(arr, size, 1, (*arr % 10));
        size++;
        arr[0] /= 10;
    }
}

void printUpTo(long long *arr, int upTo)
{
    for (int i = 0; i < upTo; i++)
    {
        printf("%lli", arr[i]);
    }
    printf("\n");
}

void printArr(long long *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%lli", arr[i]);
    }
    printf("\n"); 
}