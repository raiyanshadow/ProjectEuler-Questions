// Special Pythagorean triplet

#include "essentials.c"

int main()
{
    timeStart();

    float a, b, c;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            a = i;
            b = j;
            c = sqrt(pow(a, 2) + pow(b, 2));
            if (a + b + c == 1000)
            {
                break;
            }
        }
        if (a + b + c == 1000)
        {
            printf("%f\n", a * b * c);
            timeEnd();
            return 0;
        }
    }
}