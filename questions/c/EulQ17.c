// Number letter counts

#include "essentials.c"

int baseNumber[] = {0 /* garbage */, 3 /* one */, 3 /* two */, 5 /* three */, 4 /* four */, 4 /* five */, 3 /* six */, 5 /* seven */, 5 /* eight */, 4 /* nine */, 3 /* ten */, 6 /* eleven */, 6 /* twelve */};
int tens[] = {0 /* garbage */, 0 /* garbage */, 4 /* twen- */, 4 /* thir- */, 3 /* for- */, 3 /* fif- */, 0 /* garbage */, 0 /* garbage */, 4 /* eigh- */, };

long long letterToNumberCount(int x);

int main()
{
    int upTo;
    scanf("%i", &upTo);
    timeStart();           
    if (upTo < 0 || upTo > 9999)
    {
        printf("Number exceeds limit \nEnter a positive number less than 10 000\n");
        return -1;
    }
    long long letterCount = letterToNumberCount(upTo);
    printf("%lli\n", letterCount);

    timeEnd();
}

long long letterToNumberCount(int x)
{
    long long ret = 0;
    int short_tmp, cmp_tmp;
    for (int i = 1; i <= x; i++)
    {
        short_tmp = 0, cmp_tmp = i;
        while (cmp_tmp != 0)
        {
            int numLen = floor(log10(cmp_tmp));
            int leftmostDigit = cmp_tmp / floor(pow(10, numLen));
            if (cmp_tmp < 13)
            {
                // get number from baseNumber array, which consists of all numbers from 1 to 12 inclusive
                short_tmp += baseNumber[cmp_tmp];
                cmp_tmp = 0;
            }
            else if (cmp_tmp >= 13 && cmp_tmp < 100)
            {
                /*
                    1st: Add suffix length
                    2nd: Add 10s digit place length, skip to 3 if num < 20
                        - Note that 50 is not fivety, but "fif"ty. Same for 80 -> "eigh"ty. 20 -> "twen"ty. 30 -> "thir"ty. 40 -> "for"ty
                        - Normal spelling for sixty, seventy and ninety
                    Optional 3rd: If num < 20
                        - Consider if number has irregular spelling. Same as 50, like 15 is "fif"teen, where as 16 is normally "six"teen
                        - Irregularly spelt numbers are 13, 15, and 18
                */
                if (cmp_tmp >= 13 && cmp_tmp < 20)
                {
                    short_tmp += 4; // -teen = 4 (count)
                }
                else
                {
                    short_tmp += 2; // -ty = 2 (count)
                }

                if (cmp_tmp >= 20 && cmp_tmp < 60 || cmp_tmp >= 80 && cmp_tmp < 90)
                {
                    short_tmp += tens[leftmostDigit]; // example: focus on 4 in 42 to get for- = 3
                }
                else
                {
                    int rightmostDigit = cmp_tmp % 10;
                    if (cmp_tmp != 13 && cmp_tmp != 15 && cmp_tmp != 18)
                    {
                        if (cmp_tmp < 20)
                        {
                            short_tmp += baseNumber[rightmostDigit];  // example: focus on 5 in 15 to get fif- = 3
                            cmp_tmp = 0;
                            break;
                        }
                        else
                        {
                            short_tmp += baseNumber[leftmostDigit]; // example: focus on 7 in 73 to get seven- = 5
                        }
                    }
                    else
                    {
                        short_tmp += tens[rightmostDigit]; // example: focus on 6 in 16 to get six- = 3
                        cmp_tmp = 0;
                        break;
                    }
                }
                cmp_tmp %= 10;
            } 
            else if (cmp_tmp >= 100 && cmp_tmp < 1000)
            {
                /*
                    Normally, add the "and" suffix if we have digits after the hundreds place
                    Similar to ones digit place, but add the "hundred" after the number
                */
                short_tmp += baseNumber[leftmostDigit];
                short_tmp += 7; // hundred = 7 (count)
                if (cmp_tmp % 100 != 0)
                {
                    short_tmp += 3; // and = 3 (count)
                }
                cmp_tmp %= 100;
            }
            else if (cmp_tmp >= 1000)
            {
                /*
                    Similar to hundreds, but instead use the word "thousand"
                    Add "and" suffix if the hundreds digit is 0
                */
                short_tmp += baseNumber[leftmostDigit];
                short_tmp += 8; // thousand = 8 (count)
                if (cmp_tmp % 1000 < 100 && cmp_tmp % 1000 > 0)
                {
                    short_tmp += 3; // and = 3 (count)
                }
                cmp_tmp %= 1000;
            }
        }
        ret += short_tmp;
    }
    return ret;
}