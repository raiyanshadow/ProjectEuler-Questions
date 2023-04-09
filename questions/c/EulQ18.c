// Maximum path sum I

#include "essentials.c"

int **writeFileLine(char *fname, int rows, int *adjustCols);
int findRoute(int **pyramid, int rows, int *adjustCols);

int main()
{
    timeStart();
    int rows = getFileLines("../../testcases/EulQ18.txt");
    int *pyramidLineLen = (int *) calloc(rows, sizeof(int));

    for (int k = 0; k < rows; k++)
    {
        int lineLen = getLineLength("../../testcases/EulQ18.txt", ' ', k + 1);
        pyramidLineLen[k] = lineLen;
    }

    int **pyramid = writeFileLine("../../testcases/EulQ18.txt", rows, pyramidLineLen);
    int route = findRoute(pyramid, rows, pyramidLineLen);
    printf("%i\n", route);

    for (int i = 0; i < rows; i++)
    {
        free(pyramid[i]);
    }
    free(pyramid);
    free(pyramidLineLen);

    timeEnd();
}

int **writeFileLine(char *fname, int rows, int *adjustCols)
{
    int i = 1, j = 0, m = 0;
    FILE *f = fopen(fname, "r");
    int ch = 0;

    int **ret = (int**) calloc(rows, sizeof(int*));
    for (int k = 0; k < rows; k++)
    {
        ret[k] = (int *) calloc(adjustCols[k], sizeof(int));
    }

    while (ch != EOF)
    {
        ch = fgetc(f);
        while (ch != '\n' && ch != EOF)
        {
            if (ch != ' ')
            {
                ret[m][j] += (int)pow(10, i) * (ch - 48);
                i--;
            }
            else
            {
                j++;
                i = 1;
            }
            ch = fgetc(f);
        }
        m++;
        j = 0;
        i = 1;
    }

    return ret;

    fclose(f);
}

int findRoute(int **pyramid, int rows, int *adjustCols)
{
    int ret = pyramid[0][0];

    for (int i = rows - 1; i > 0; i--)
    {
        int *lineCopy = (int *) calloc(adjustCols[i - 1], sizeof(int));
        for (int j = 0; j < adjustCols[i - 1]; j++)
        {
            lineCopy[j] = MAX(pyramid[i][j], pyramid[i][j + 1]) + pyramid[i - 1][j];
        }
        pyramid[i - 1] = arrCopy(lineCopy, adjustCols[i - 1]);
        free(lineCopy);
    }

    ret += MAX(pyramid[1][0], pyramid[1][1]);

    return ret;
}