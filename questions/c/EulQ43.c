// Sub-string divisibility

#include "essentials.c"

int primes[] = {2, 3, 5, 7, 11, 13, 17};
int checks = 7;
char min_num[] = {'1', '0', '2', '4', '6', '5', '8', '3', '9', '7'};

bool substringCheck(long long x);
int substring(int *x, int startIdx);
void llToIntArr(int *arr, long long x);
void reverse(char *string, int left, int right);
void swap(char *arr, int i1, int i2);
bool nextPermutation(char *string);
int binSearch(char *string, int left, int right, int key);

int main()
{
    timeStart();

    char *str = (char *) malloc(11 * sizeof(char));
    for (int i = 0; i < 10; i++)
    {
        str[i] = min_num[i];
    }
    str[10] = '\0';
    long long ret = 0;

    while (nextPermutation(str))
    {
        long long longnum = atoll(str);
        if (!isPandigital(longnum, 10, true))
        {
            continue;
        }
        if (substringCheck(longnum))
        {
            ret += longnum;
        }
    }

    free(str);
    printf("%lli\n", ret);

    timeEnd();
}

bool substringCheck(long long x)
{
    int* subs = (int*) calloc(10, sizeof(int));
    llToIntArr(subs, x);
    for (int i = 0; i < checks; i++)
    {
        int sub = substring(subs, i + 2);
        if (sub % primes[i] == 0)
        {
            continue;
        }
        else
        {
            free(subs);
            return false;
        }
    }
    free(subs);
    return true;
}

int substring(int* x, int startIdx)
{
    return (x[startIdx - 1] * 100) + (x[startIdx] * 10) + (x[startIdx + 1]);
}

void llToIntArr(int *arr, long long x)
{
    long long copy = x;
    for (int i = 9; i >= 0; i--)
    {
        arr[i] = copy % 10;
        copy /= 10;
    }
}

int binSearch(char *string, int left, int right, int key)
{
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (string[mid] <= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            if (index == -1 || string[index] >= string[mid])
            {
                index = mid;
            }
        }
    }
    return index;
}

bool nextPermutation(char *string)
{
    int len = strlen(string);
    int i = len - 2;
    while (i >= 0 && string[i] >= string[i + 1])
    {
        i--;
    }
    if (i < 0)
    {
        return false;
    }
    else
    {
        int index = binSearch(string, i + 1, len - 1, string[i]);
        swap(string, i, index);
        reverse(string, i + 1, len - 1);
        return true;
    }
}

void swap(char *arr, int i1, int i2)
{
    if (arr[i1] == arr[i2])
    {
        return;
    }
    char tmp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = tmp;
}

void reverse(char *string, int left, int right)
{
    while (left < right)
    {
        swap(string, left++, right--);
    }
}