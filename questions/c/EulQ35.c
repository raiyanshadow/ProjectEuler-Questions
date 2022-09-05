// Circular primes

#include "essentials.c"

int findCircularPrimes(int under);
void leftShift(int *numArr, int digitLen);
bool testCircularPrime(int num);
int arrToInt(int *num, int digitLen);
void intToArr(int *numArr, int digitLen, int intNum);

int main()
{
    int under;
    scanf("%i", &under);

    timeStart();

    int x = findCircularPrimes(under);
    printf("%i\n", x);

    timeEnd();
}

int findCircularPrimes(int under)
{
    int ret = 0;
    for (int i = 2; i < under; i++)
    {
        if(testCircularPrime(i))
        {
            printf("prime found: %i\n", i);
            ret++;
        }
    }
    return ret;
}

bool testCircularPrime(int num)
{
    bool ret = true;
    if (isPrime(num))
    {
        int numLen = floor(log10(num)) + 1;
        if (numLen == 1)
        {
            return true;
        }
        else
        {
            int *intArr = (int *) calloc(numLen, sizeof(int));
            intToArr(intArr, numLen, num);
            for (int i = 0; i < numLen - 1; i++)
            {
                leftShift(intArr, numLen);
                int tmp = arrToInt(intArr, numLen);
                if (isPrime(tmp))
                {
                    ret = true;
                    continue;
                }
                else
                {
                    ret = false;
                    break;
                }
            }
            free(intArr);
            return ret;
        }
    }
    return false;
}

int arrToInt(int *num, int digitLen)
{
    int ret = 0;
    int multiplier = (int)pow(10, digitLen - 1);
    for (int i = 0; i < digitLen; i++, multiplier /= 10)
    {
        ret += num[i] * multiplier;
    }
    return ret;
}

void leftShift(int *numArr, int digitLen)
{
    for (int i = 0; i < digitLen - 1; i++)
    {
        int tmp = numArr[i + 1];
        numArr[i + 1] = numArr[i];
        numArr[i] = tmp;
    }
}

void intToArr(int *numArr, int digitLen, int intNum)
{
    int len = digitLen - 1;
    for (int i = 0; i < digitLen; i++, len--)
    {
        int flux = (int)pow(10, len);
        numArr[i] = intNum / flux;
        intNum %= flux;
    }
}