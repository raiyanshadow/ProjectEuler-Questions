// Prime digit replacement
// runtime is a bit long (~2s) but it works for now

#include "essentials.c"

void deepFree(bool ***adjMat, int s1, int s2[]);
void makeGroupPerms(bool **adjMat, int size, int digitLen);
void binaryAddOne(int *bin, int digitLen);
void lpdrf(bool ***familyGroup);
long long makeNum(bool *familyGroup, int digitLen, int numToFill, int initialNum);

// notice how the number of permutations of is (dec(1111...1) with n repeating digits of 1 where n is the length of the number)
// converting the 111...1 to decimal gives us the number of permutations interestingly
int sizes[] = {1, 3, 7, 15, 31, 63, 127, 255, 511};

int main()
{
    timeStart();
    // family group permutation generation takes 0 ms so thats good
    bool ***familyGroup = (bool ***)calloc(9, sizeof(bool**));
    for (int i = 0; i < 9; i++)
    {
        familyGroup[i] = (bool **)calloc(sizes[i], sizeof(bool*));
        for (int j = 0; j < sizes[i]; j++)
        {
            familyGroup[i][j] = (bool*)calloc((i + 1), sizeof(bool));
        }
        makeGroupPerms(familyGroup[i], sizes[i], (i + 1));
    }

    lpdrf(familyGroup);
}

void deepFree(bool ***adjMat, int s1, int s2[])
{
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2[i]; j++)
        {
            free(adjMat[i][j]);
        }
        free(adjMat[i]);
    }
    free(adjMat);
}

// let us interpret a binary number that is n digits long, where n is the length of the number
// if we add 1 each time, this represents 1 permutation
// example if we have a 3 digit number (526), then starting binary is 00, which we dont include
// then         001 - meaning 52*
// then         010 - meaning 5*6
// then         011 - meaning 5**
// then         100 - meaning *26
// then         101 - meaning *2*
// then         110 - meaning **6
// finally then 111 - meaning ***

void makeGroupPerms(bool **adjMat, int size, int digitLen)
{
    int *bin = (int*)calloc(digitLen, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        binaryAddOne(bin, digitLen);
        for (int j = 0; j < digitLen; j++)
        {
            adjMat[i][j] = (bool)bin[j];
        }
    }
    free(bin);
}


// simply just adds one to the binary number
// done by using simple binary addition arithmetic
void binaryAddOne(int *bin, int digitLen)
{
    int i = digitLen - 1;
    while (i >= 0)
    {
        if (bin[i] == 1)
        {
            bin[i] = 0;
            i--;
        }
        else
        {
            bin[i] = 1;
            return;
        }
    }
}

// Find lowest prime digit replacement family
void lpdrf(bool ***familyGroup)
{
    int y = 1e9;
    for (int i = 4; i < 9; i++)
    {
        long long max = (long long)pow(10, i + 1) - 1;
        for (long long j = (long long)pow(10, i); j <= max; j++)
        {
            if (isPrime(j))
            {
                for (int k = 0; k < sizes[i]; k++)
                {
                    y = 1e9; // dummy value
                    int count = 0;
                    for (int m = 0; m < 10; m++)
                    {
                        long long x = makeNum(familyGroup[i][k], i + 1, m, j);
                        if ((floor(log10(x)) + 1) != (i + 1))
                        {
                            continue;
                        }
                        if (isPrime(x) == 1)
                        {
                            y = MIN(y, x);
                            count++;
                        }
                    }
                    if (count == 8)
                    {
                        printf("%lli\n", y);
                        deepFree(familyGroup, 9, sizes);
                        timeEnd();
                        return 0;
                    }
                }
            }
        }
    }
}

long long makeNum(bool *familyGroup, int digitLen, int numToFill, int initialNum)
{
    long long ret = initialNum; 
    long long copy = initialNum;
    for (int i = digitLen - 1, j = 1; i >= 0; i--, j *= 10)
    {
        int curNum = copy % 10;
        if (familyGroup[i])
        {
            ret = ret - (curNum*j);
            ret = ret + (numToFill*j);
        }
        copy /= 10;
    }
    return ret;
}