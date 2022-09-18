// Prime permuations
// Permutation functions gotten from question 23

#include "essentials.c"

bool nextPermutation(char *string);                           
void swap(char *arr, int i1, int i2);
void reverse(char *string, int left, int right);
int binSearch(char *string, int left, int right, int key);
bool primePermutationChecked(char **str, int size);
void copy(char *dst, char* src, int size);
void deepFree(char **mat, int size);

int main()
{
    timeStart();

    char **nums = calloc(1, sizeof(char*));
    nums[0] = calloc(5, sizeof(char));
    int size = 0;

    for (int i = 1488; i <= 9999; i++)
    {
        if (isPrime(i))
        {
            nums = calloc(1, sizeof(char*));
            nums[0] = calloc(5, sizeof(char));
            itoa(i, nums[0], 10);
            char *tmp = calloc(5, sizeof(char));
            tmp[4] = '\0';
            size = 1;
            copy(tmp, nums[0], 4);
            int i = 0;
            while (nextPermutation(tmp))
            {
                i++;
                nums = realloc(nums, (1 + size) * sizeof(char *));
                nums[i] = calloc(5, sizeof(char));
                strcpy(nums[i], tmp);
                size++;
            }
            free(tmp);
            if (size > 2 && primePermutationChecked(nums, size))
            {
                deepFree(nums, size);
                timeEnd();
                return 0;
            }
            deepFree(nums, size);
        }
    }

    deepFree(nums, size);
    timeEnd();
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

bool primePermutationChecked(char **str, int size)
{
    int tmp = atoi(str[0]);
    int diff = 0;
    for (int i = 1; i < size; i++)
    {
        int stra = atoi(str[i]);
        diff = stra-tmp;
        for (int j = 1; j < size; j++)
        {
            if (i == j)
            {
                continue;
            }
            int strb = atoi(str[j]);
            if (abs(strb - stra) == diff)
            {
                if (isPrime(stra) && isPrime(strb))
                {
                    printf("%s%s%s\n", str[0], str[i], str[j]);
                    return true;
                }
            }
            else
            {
                continue;
            }
        }
    }
    
    return false;
}

void copy(char *dst, char* src, int size)
{
    for (int i = 0; i < size; i++)
    {
        dst[i] = src[i];
    }
}

void deepFree(char **mat, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(mat[i]);
    }
    free(mat);
}