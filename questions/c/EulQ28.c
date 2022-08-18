// Number spiral diagonals

#include "essentials.c"

long long sumSpiralDiagonals(int rows);

int main()
{
    int rows;
    scanf("%i", &rows);

    timeStart();

    long long sumSpiral = sumSpiralDiagonals(rows);
    printf("%lli\n", sumSpiral);

    timeEnd();
}

long long sumSpiralDiagonals(int rows)
{
    long long ret = 1;
    long long max = rows * rows;
    long long track = 1;
    int curRow = 3;
    int tmpStart = 1;
    while (track <= max)
    {
        int tmpMax = curRow * curRow;
        tmpStart += (curRow - 1);
        int i = tmpStart;
        for (int i = tmpStart; i <= tmpMax; )
        {
            ret += i;
            i += (curRow - 1);
        }
        tmpStart = tmpMax;
        curRow += 2;
        track = curRow * curRow;
    }
    return ret;
}