// Pentagon numbers

/* 
   Given that P_n = n(3n - 1)/2, then
   let P_n = a
   a = (3n^2 - n)/2
   2a = 3n^2 - n
   0 = 3n^2 - n - 2a
   n = 1 +- sqrt(1 - 4*3*-2a)/2*3
   n = 1 +- sqrt(1 + 24a)/6
   and since n must be in the set of positive integers
   n = 1 + sqrt(1 + 24a)/6
*/ 

#include "essentials.c"

int main()
{
    timeStart();

    long long* pentagons = (long long*) calloc(2, sizeof(long long));
    pentagons[0] = 0;
    pentagons[1] = 1;
    int min = 0;

    int i = 2;
    while (true)
    {
        pentagons = (long long *) realloc(pentagons, (i + 1) * sizeof(long long));
        pentagons[i] = (i * (3 * i - 1)) / 2;
        for (int j = 1; j < i; j++)
        {
            float n2 = (1 + sqrt(1 + (24*(pentagons[i] - pentagons[j])))) / 6;
            if (floor(n2) == n2)
            {
                float n1 = (1 + sqrt(1 + (24*(pentagons[i] + pentagons[j])))) / 6;   
                if (floor(n1) == n1)
                {
                    printf("%lli\n", llabs(pentagons[i] - pentagons[j]));
                    free(pentagons);
                    timeEnd();
                    return 0;
                }
            }
        } 
        i++;
    }

    free(pentagons);   
    timeEnd(); 

    timeEnd();
}