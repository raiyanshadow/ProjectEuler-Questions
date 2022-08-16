// Lexicographic permutations

#include "essentials.c"

void reverse(char *string, int left, int right);
void swap(char *arr, int i1, int i2);
bool nextPermutation(char *string);
int binSearch(char *string, int left, int right, int key);

int main()
{
    int nums;
    scanf("%i", &nums);
    timeStart();

    char *letters = (char *) malloc(nums + 1 * sizeof(char));
    for (int i = 0; i < nums; i++)
    {
        letters[i] = (char) i + 48;
    }
    letters[nums] = '\0';

    for (int i = 1; i <= 999999; i++)
    {
        nextPermutation(letters);
    }
    
    for (int i = 0; i < nums; i++)
    {
        printf("%c", letters[i]);
    }
    printf("\n");
    free(letters);

    timeEnd();
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