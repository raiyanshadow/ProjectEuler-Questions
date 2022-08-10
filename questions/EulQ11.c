// Largest product in a grid
// WIP

#include "essentials.c"

int **readFile(int **mat, char *fname);

int main()
{
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
