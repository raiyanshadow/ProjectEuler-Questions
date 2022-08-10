// Largest product in a grid

#include "essentials.c"

int **readFile(int **mat, char *fname);
long long matrixMaxProd(int **grid, int rows, int cols, int adjacentDigits);

int main()
{
    int adjacentDigits;
    scanf("%i", &adjacentDigits);

    timeStart();

    int x = getFileLines("../testcases/EulQ11.txt");
    int y = getLineLength("../testcases/EulQ11.txt");

    int **matrix = calloc(x, sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        matrix[i] = calloc(y, sizeof(int));
    }

    matrix = readFile(matrix, "../testcases/EulQ11.txt");

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%i, ", matrix[i][j]);
        }
        printf("\n");
    }

    long long prod = matrixMaxProd(matrix, x, y, adjacentDigits);
    printf("%lli\n", prod);

    timeEnd();
    for (int i = 0; i < x; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

int** readFile(int **mat, char *fname)
{
    int i = 0, j = 0;
    FILE *f = fopen(fname, "r");
    int ch = 0;

    while (ch != EOF)
    {
        int prevch = ch;
        ch = fgetc(f);
        if (ch != ' ' && ch != '\n' && ch != EOF)
        {
            if (prevch != ' ' && prevch != '\n')
            {
                mat[i][j] += ch - 48;
            }
            else
            {
                mat[i][j] += (ch - 48) * 10;
            }
        }
        else if (ch == ' ')
        {
            j++;
        }
        else if (ch == '\n')
        {
            i++;
            j = 0;
        }
    }

    fclose(f);

    return mat;
}

long long matrixMaxProd(int **grid, int rows, int cols, int adjacentDigits)
{
    bool up = false, down = false, right = false, left = false;
    bool uright = false, uleft = false, dleft = false, dright = false;
    long long ret = 0, tmp = 1;
    adjacentDigits--;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }

            up = i >= adjacentDigits ? true : false;
            down = adjacentDigits >= i ? true : false;
            right = adjacentDigits >= j ? true : false;
            left = j >= adjacentDigits ? true : false;
            uright = (up && right) ? true : false;
            uleft = (up && left) ? true : false;
            dright = (down && right) ? true : false;
            dleft = (down && left) ? true : false;

            if (up)
            {
                for (int count = 0, m = i; count <= adjacentDigits; count++, m--)
                {
                    tmp *= grid[m][j];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (down)
            {
                for (int count = 0, m = i; count <= adjacentDigits; count++, m++)
                {
                    tmp *= grid[m][j];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (right)
            {
                for (int count = 0, n = j; count <= adjacentDigits; count++, n++)
                {
                    tmp *= grid[i][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (left)
            {
                for (int count = 0, n = j; count <= adjacentDigits; count++, n--)
                {
                    tmp *= grid[i][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (uright)
            {
                for (int count = 0, m = i, n = j; count <= adjacentDigits; count++, n++, m--)
                {
                    tmp *= grid[m][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (uleft)
            {
                for (int count = 0, m = i, n = j; count <= adjacentDigits; count++, m--, n--)
                {
                    tmp *= grid[m][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (dright)
            {
                for (int count = 0, m = i, n = j; count <= adjacentDigits; count++, m++, n++)
                {
                    tmp *= grid[m][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
            if (dleft)
            {
                for (int count = 0, m = i, n = j; count <= adjacentDigits; count++, m++, n--)
                {
                    tmp *= grid[m][n];
                }
                ret = MAX(ret, tmp);
                tmp = 1;
            }
        }
    }

    return ret;
}
