// Coded triangle numbers

/* 

    given the formula t_n = 1/2 * n * (n + 1)
    then let a = t_n
    then a = 1/2 * n * (n + 1)
    2a = n^2 + n
    0 = n^2 + n - 2a
    n = (-1 +- sqrt(1 + 8a)) / 2
    n = -1 + sqrt(1 + 8a) / 2      where n has to be a postive integer

*/

#include "essentials.c"

bool exists(int a);
int findTriangles(char *fname);

int main()
{
    timeStart();

    char *fname = "../../testcases/EulQ42.txt";
    int ret = findTriangles(fname);
    printf("%i\n", ret);

    timeEnd();
}

bool exists(int a)
{
    float ret = (-1 + sqrt(1 + 8*a)) / 2;
    return (floor(ret) == ret);
}

int findTriangles(char *fname)
{
    FILE *f = fopen(fname, "r");
    int ch = 0;
    int wordSum = 0;
    int ret = 0;

    while (ch != EOF)
    {
        ch = fgetc(f);
        if (ch == ',')
        {
            if (exists(wordSum))
            {
                ret++;
            }
            wordSum = 0;
        }
        else if (ch != '"')
        {
            wordSum += ch - 64;
        }
    }

    fclose(f);
    return ret;
}