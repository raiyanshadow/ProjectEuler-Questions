#include "essentials.h"

void timeStart()
{
    TIME_START = (float) clock () / CLOCKS_PER_SEC; 
}

void timeEnd()
{
    TIME_END = (float) clock () / CLOCKS_PER_SEC;
    printf("Time elapsed: %f", TIME_END-TIME_START);
}

int isPrime(long long x)
{   
    if (x < 2)
    {
        return 2;
    }
    long long ret = 2;
    while (ret * ret <= x)
    {
        if (x % ret == 0)
        {
            return 0;
        }
        ret++;
    }
    return 1;
}

int getFileLines(char *fname)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int ret = 0;

    while (ch != EOF)
    {
        ch = fgetc(f);
        if (ch == '\n')
        {
            ret++;
        }
    }

    fclose(f);

    return ret + 1;
}

int getLineLength(char *fname, char sep)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int ret = 0;
    char tmpsep = sep;

    while (ch != '\n')
    {
        ch = fgetc(f);
        if (tmpsep == 0)
        {
            sep = ch;
        }
        if (ch == sep && ch != '\n')
        {
            ret++;
        }
    }

    if (tmpsep == 0)
    {
        return ret;
    }
    return ret + 1;
}
