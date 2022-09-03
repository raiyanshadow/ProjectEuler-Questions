// Digit factorials

#include "essentials.c"

int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

long long SDF();
long long digitFactorial(long long x);

int main()
{
    timeStart();

    long long ret = SDF();
    printf("%lli\n", ret);

    timeEnd();
}

long long SDF()
{
    // logic should be that the max is 7*9! = 2540160, which is a 7 digit number
    // meaning that any higher, and 8 9s would not make sense since 8*9! = 2903040, a 7 digit number which cannot have 8 9s
    // but the upper limit can be set to 9! ? 
    // works but I dont understand myself
    long long max = digitFactorial(9);
    long long ret = 0;
    for (long long i = 3; i <= max; i++)
    {
        if (digitFactorial(i) == i)
        {
            ret += i;
        }
    }
    return ret;
}

long long digitFactorial(long long x)
{
    int len = floor(log10(x));
    int ret = 0;
    long long copy = x;
    for (int i = len; i >= 0; i--)
    {
        int off = (int)pow(10, i);
        ret += factorials[copy / off];
        copy %= off;
    }
    return ret;
}