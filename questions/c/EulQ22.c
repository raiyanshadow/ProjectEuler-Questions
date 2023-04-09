// Name scores

#include "essentials.c"

void makeStringArr(char *fname, char **arr);
int lexicogaphicSort(char *a, char *b);
void string_sort(char **arr, int len, int (*cmp_func)(char *a, char *b));
long long nameScoreSum(char **arr, int size);

int main()
{
    timeStart();

    int numNames = getLineLength("../../testcases/EulQ22.txt", ',', 1);
    char **stringArr = (char **) malloc(numNames * sizeof(char *));

    for (int i = 0; i < numNames; i++)
    {
        stringArr[i] = (char *) malloc(1 * sizeof(char));
    }

    makeStringArr("../../testcases/EulQ22.txt", stringArr);
    string_sort(stringArr, numNames, lexicogaphicSort);

    long long sum = nameScoreSum(stringArr, numNames);
    printf("%lli\n", sum);

    for (int i = 0; i < numNames; i++)
    {
        free(stringArr[i]);
    }

    free(stringArr);

    timeEnd();
}

void makeStringArr(char *fname, char **arr)
{
    FILE *f = fopen(fname, "r");
    int i = 0, j = 0;
    int ch = 0, check = 1;

    while (ch != EOF)
    {
        ch = fgetc(f);
        if (ch == '\"' && check == 1)
        {
            check = check * -1;
            j = 0;
        }
        else if (ch == '\"' && check == -1)
        {
            arr[i] = (char *) realloc(arr[i], (j + 1) * sizeof(char));
            check = check * -1;
            arr[i][j] = '\0';
            i++;
        }
        else if (ch != ',' && ch != EOF)
        {
            arr[i] = (char*) realloc(arr[i], (j + 1) * sizeof(char));
            arr[i][j] = ch;
            j++;
        }
    }

    fclose(f);
}

int lexicogaphicSort(char *a, char *b)
{
    return strcmp(a, b);
}

void string_sort(char **arr, int len, int (*cmp_func)(char *a, char *b))
{
    // Simple Shell sort
    for (int i = len / 2; i > 0; i /= 2)
    {
        for (int j = i; j < len; j++)
        {
            for (int k = j - i; k >= 0; k -= i)
            {
                if (cmp_func(arr[k + i], arr[k]) > 0)
                {
                    break;
                }
                else
                {
                    char *tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}

long long nameScoreSum(char **arr, int size)
{
    long long ret = 0;
    for (int i = 0; i < size; i++)
    {
        int tmp = 0;
        for (int j = 0; j < strlen(arr[i]); j++)
        {
            tmp += (arr[i][j] - 'A') + 1;
        }
        tmp *= (i + 1);
        ret += tmp;
    }
    return ret;
}