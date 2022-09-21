// Permuted multiples

#include "essentials.c"

int check_a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int check_b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool similarDigitsCheck(long long x);
void makeCheck(long long x, int arr[]);
void reset(int arr[], int size);

int main()
{
    timeStart();

    bool flag;
    for (long long i = 1;; i++)
    {
        flag = true;
        makeCheck(i, check_a);
        for (long long j = 2; j <= 6; j++)
        {
            if (!similarDigitsCheck(j*i))
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            printf("%lli\n", i);
            timeEnd();
            return 0;
        }
    }

    timeEnd();
}

bool similarDigitsCheck(long long x)
{
    makeCheck(x, check_b);
    for (int i = 0; i < 10; i++)
    {
        if (check_a[i] != check_b[i])
        {
            reset(check_a, 10);
            reset(check_b, 10);
            return false;
        }
    }
    reset(check_b, 10);
    return true;
}

void makeCheck(long long x, int arr[])
{
    long long copy = x;
    while (copy != 0)
    {
        arr[copy % 10]++;
        copy /= 10;
    }
}

void reset(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}