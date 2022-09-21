// Combinatoric selections
// slow and bad method lmao

#include "essentials.c"

int main()
{
    timeStart();

    int count = 0;

    bignum million;
    int_to_bignum(1000000, &million);

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            bignum combinatoric;
            choose(i, j, &combinatoric);
            if (compare_bignum(&combinatoric, &million) == -1)
            {
                count++;
            }
        }
    }

    printf("%i\n", count);
    timeEnd();
}