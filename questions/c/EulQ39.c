// Integer Right Triangles

// kind of slow but works

#include "essentials.c"

int main()
{
    timeStart();

    int count = 0;
    int max = 0;
    int maxpos = 0;
    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)                     // side length
        {
            for (int k = 1; k <= i - j; k++)             // other side length
            {
                float hyp = sqrt((j * j) + (k * k));
                if (j + k + hyp > i)
                {
                    break;
                } 
                if (floor(hyp) == hyp)
                {
                    if ((float)j + (float)k + hyp == i)
                    {
                        count++;
                    }
                }
            }
        }
        if (count >= max)
        {
            max = count;
            maxpos = i;
        }
        count = 0;
    }
    printf("%i\n", maxpos);
    timeEnd();
}
