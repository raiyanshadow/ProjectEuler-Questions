// Coin sums

#include "essentials.c"

#define COINS 8
int pences[] = {1, 2, 5, 10, 20, 50, 100, 200};

void countWays(int **matrix, int size);

int main()
{
    int n;
    scanf("%i", &n);
    timeStart();
    int **mat = (int **) calloc(COINS, sizeof(int *));
    for (int i = 0; i < COINS; i++)
    {
        mat[i] = (int *) calloc(n + 1, sizeof(int));
    }

    countWays(mat, n + 1);
    printf("%i\n", mat[COINS - 1][n] + 1);

    for (int i = 0; i < COINS; i++)
    {
        free(mat[i]);
    }
    free(mat);
    /* front end developer code be like :p
    int ret = 0;
    
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            for (int k = 0; k <= 40; k++)
            {
                for (int l = 0; l <= 20; l++)
                {
                    for (int m = 0; m <= 10; m++)
                    {
                        for (int n = 0; n <= 4; n++)
                        {
                            for (int o = 0; o <= 2; o++)
                            {
                                for (int p = 0; p <= 1; p++)
                                {
                                    if (((p * 200) + (o * 100) + (n * 50) + (m * 20) + (l * 10) + (k * 5) + (j * 2) + i) == 200)
                                    {
                                        ret++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%i\n", ret);
    */



    timeEnd();
}

void countWays(int **matrix, int size)
{
    matrix[0][0] = 1;
    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = j >= pences[i - 1] ? matrix[i - 1][j] + matrix[i][j - pences[i - 1]] : matrix[i - 1][j];
        }
    }
}