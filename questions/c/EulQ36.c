// Double-base palindromes

#include "essentials.c"

bool isDecimalPalindrome(int x);
bool isBinaryPalindrome(int* bin, int binLen);
void decimalToBinary(int num, int *bin, int binLen);
bool equalBinaries(int* bin1, int* bin2, int size);

int main()
{
    int under;
    scanf("%i", &under);
    timeStart();

    long long ret = 0;
    for (int i = 1; i < under; i++)
    {
        if (isDecimalPalindrome(i) && i % 2 != 0)
        {
            int binLen = floor(log2(i)) + 1; 
            int *bin = (int *) calloc(binLen, sizeof(int));
            decimalToBinary(i, bin, binLen);
            if (isBinaryPalindrome(bin, binLen))
            {
                ret += i;
            }
            free(bin);
        }
    }
    printf("%lli\n", ret);

    timeEnd();
}

bool isDecimalPalindrome(int x)
{
    int copy = 0, tmpcopy = x;
    while (x != 0)
    {
        copy = copy * 10 + x % 10;
        x /= 10;
    }

    return (tmpcopy == copy);
}

bool isBinaryPalindrome(int* bin, int binLen)
{
    for (int i = 0, j = binLen - 1; i < binLen / 2; i++, j--)
    {
        if (bin[i] != bin[j])
        {
            return false;
        }
    }
    return true;
}

void reverseArr(int *arr, int size)
{
    for (int i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

void decimalToBinary(int num, int *bin, int binLen)
{
    int pos = binLen - 1;
    int copy = num;

    while (copy != 1)
    {
        bin[pos] = copy % 2;
        copy /= 2;
        pos--;
    }   
    bin[0] = 1;
}
