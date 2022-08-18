// Digit fifth powers

#include "essentials.c"

long long sumDigitPowers(int exp);
long long findMax(int exp);

int main()
{
    int exp;
    scanf("%i", &exp);
    timeStart();

    long long sum = sumDigitPowers(exp);
    printf("%lli\n", sum);

    timeEnd();
}

long long sumDigitPowers(int exp)
{
    long long ret = 0;
    long long max = findMax(exp);
    for (long long i = 2; i < max; i++)
    {
        int len = floor(log10(i)) + 1;
        int tmp = i;
        long long sum = 0;
        for (int j = 0; j < len; j++)
        {
            long long x = tmp / (int)pow(10, (len - j - 1));
            x = (long long)pow(x, exp);
            sum += x;
            tmp %= (int)pow(10, (len - j - 1));
        }
        if (sum == i)
        {
            ret += sum;
        }
    }
    return ret;
}

long long findMax(int exp)
{
    int ret = 1;
    while (floor(log10(ret * (int)pow(9, exp))) + 1 >= ret)
    {
        ret += 1;
    }
    return ret * pow(9, exp);
}