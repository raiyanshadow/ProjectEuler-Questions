// Triangular, pentagonal, and hexagonal

/* 
   Let T_n = n(n + 1) / 2
   And H_n = n(2*n - 1)
   Then notice if n = 2m - 1 for T_n, that
   T_n = (2m - 1)(2m - 1 + 1) / 2 = 2m(2m - 1) / 2 = m(2m - 1) = H_n
   Meaning that T_n is equal to H_m at all times for some m in the set of positve integers
*/

#include "essentials.c"
#define START 143

int main()
{
    timeStart();
    for (int i = START + 1; ;i++)
    {
        long long h = i * (2 * i - 1);
        double p = (1 + sqrt(1 + 24*h))/6;
        if (floor(p) == p)
        {
            printf("%lli\n", h);
            timeEnd();
            return 0;
        }
    }
}