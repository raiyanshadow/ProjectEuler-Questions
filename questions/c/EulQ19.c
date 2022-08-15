// Counting sundays

#include "essentials.c"

int months[] = { 31, 28,  31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int numMonths = 12;

int countSundays(int startDate, int endDate);

int main()
{
    timeStart();

    int count = countSundays(1901, 2000);
    printf("%i\n", count);

    timeEnd();
}

int countSundays(int startDate, int endDate)
{
    int k = 1;
    int m = 11;
    int _D = startDate % 100;
    int _C = startDate / 100;
    // Zellers rule to find the day of Jan 01, 1901
    int startDay = k + ((13* m - 1) / 5) + _D + (_D / 4) + (_C / 4) - 2 * _C;
    int ret = 0;
    for (int i = startDate; i <= endDate; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            months[1] = 29;
        }
        else
        {
            months[1] = 28;
        }
        for (int j = 0; j < numMonths; j++)
        {
            startDay += months[j] % 7;
            if (startDay % 7 == 0)
            {
                ret++;
            }
        }
    }
    return ret;
}