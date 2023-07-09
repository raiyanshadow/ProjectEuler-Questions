// Cyclical Figurate Numbers
// was actually difficult...

#include "essentials.c"

void makeFigurates(int*** figurateSet, int** sizes);
bool isCyclical(int a, int b);
bool cyclicalSet(orderedPair*set, int size);
bool orderedCyclicalSet(orderedPair *set, int size);
int missing(orderedPair *set);

int main()
{
    timeStart();
    
    int** figurateSet = malloc(6*sizeof(int*));
    figurateSet[0] = malloc(96*sizeof(int));
    figurateSet[1] = malloc(68*sizeof(int));
    figurateSet[2] = malloc(56*sizeof(int));
    figurateSet[3] = malloc(48*sizeof(int));
    figurateSet[4] = malloc(43*sizeof(int));
    figurateSet[5] = malloc(40*sizeof(int));
    int* setSize = malloc(6*sizeof(int));
    orderedPair *finalSet = malloc(sizeof(orderedPair)); 
    int *cache = malloc(sizeof(int));
    makeFigurates(&figurateSet, &setSize);
    int fsize = 1;
    cache[0] = 0;
    bool trueflag = false;

    for (int i = 0; i < setSize[0] && !trueflag; i++)
    {
        finalSet = realloc(finalSet, sizeof(orderedPair));
        finalSet[0].y = figurateSet[0][i];
        finalSet[0].x = 0;
        int a = 1;
        int preva = 0;
        fsize = 1;
        trueflag = false;
        for (int l = 1; l < 6 && !trueflag; l++)
        {
            fsize = 1;
            a = l;
            cache = realloc(cache, sizeof(int));
            finalSet = realloc(finalSet, sizeof(orderedPair));
            int cachesize = 1;
            preva = a;
            int count[7] = {0, 0, 0, 0, 0, 0, 0};
            for (int j = 0; ; j++)
            {
                if (fsize == 6)
                {
                    if (orderedCyclicalSet(finalSet, 6))
                    {
                        trueflag = true;
                        break;
                    }
                }
                if ((a + 1) % 6 == preva)
                {
                    if (fsize == 1)
                    {
                        break;
                    }
                    fsize--;
                    a = finalSet[fsize].x;
                    j = intPosSeenIn(finalSet[fsize].y, figurateSet[a], setSize[a]) + 1;
                    finalSet = realloc(finalSet, fsize*sizeof(orderedPair));
                    cachesize = fsize;
                    cache = realloc(cache, cachesize*sizeof(int));
                    bool flag = false;
                    for (int h = j; h < setSize[a]-1; h++)
                    {
                        if (isCyclical(finalSet[fsize-1].y, figurateSet[a][h]))
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        cachesize++;
                        cache = realloc(cache, cachesize*sizeof(int));
                        cache[cachesize-1] = a;
                        a = (a+1)%6;
                        j = -1;
                    }
                    count[fsize]++;
                    for (int h = fsize+1; h < 7; h++)
                    {
                        count[h] = 0;
                    }
                    if (count[fsize] == 7-fsize)
                    {
                        break;
                    }
                }
                if (intSeenIn(a, cache, cachesize))
                {
                    a = (a + 1) % 6;
                    j = -1;
                    continue;
                }
                if (isCyclical(finalSet[fsize-1].y, figurateSet[a][j]))
                {
                    fsize++;
                    finalSet = realloc(finalSet, fsize*sizeof(orderedPair));
                    finalSet[fsize-1].y = figurateSet[a%6][j];
                    finalSet[fsize-1].x = a;
                    cache = realloc(cache, fsize*sizeof(int));
                    cache[fsize-1] = a;
                    cachesize = fsize;
                    j = -1;
                    if (fsize == 5)
                    {
                        bool flag = false;
                        int x = missing(finalSet);
                        if (x == finalSet[fsize-1].x - 1)
                        {
                            for (int h = 0; h < setSize[a-1]; h++)
                            {
                                if (isCyclical(finalSet[fsize-1].y, figurateSet[x][h]))
                                {
                                    fsize++;
                                    finalSet = realloc(finalSet, fsize*sizeof(orderedPair));
                                    finalSet[fsize-1].y = figurateSet[x][h];
                                    finalSet[fsize-1].x = x;
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if (flag)
                        {
                            if (orderedCyclicalSet(finalSet, fsize))
                            {
                                trueflag = true;
                                break;
                            }
                        }
                    }
                    preva = a;
                    a = (a + 1) % 6;
                    
                }
                else if (j == setSize[a]-1)
                {
                    if ((a+1)%6 != preva)
                    {
                        cachesize++;
                        cache = realloc(cache, cachesize*sizeof(int));
                        cache[cachesize-1] = a;
                        if (intSeenIn(((a-1)%6), cache, fsize))
                        {
                            a = (a + 1) % 6;
                            j = -1;
                            continue;
                        }
                        j = intPosSeenIn(finalSet[fsize-1].y, figurateSet[a], setSize[a]);
                        a = (a-1)%6;
                        continue;
                    }
                    else
                    {
                        a = (a + 1) % 6;
                        j = -1;
                    }
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("%i, ", finalSet[i].y);
        ret += finalSet[i].y;
    }
    printf("\n%i\n", ret);

    for (int i = 0; i < 6; i++)
    {
        free(figurateSet[i]);
    }
    free(figurateSet);
    free(finalSet);
    free(cache);
    timeEnd();
}

int missing(orderedPair *set)
{
    for (int i = 1; i < 6; i++)
    {
        bool flag = false;
        for (int j = 0; j < 6; j++)
        {
            flag = true;
            if (set[j].x == i)
            {
                flag = false;
                break;
            }

        }
        if (flag)
        {
            return i;
        }
    }
    return -1;
}

void makeFigurates(int*** figurateSet, int** sizes)
{
    // triangle
    int remove = 0;
    for (int n = 45, a = 0; n <= 140; n++, a++)
    {
        int x = (int)(n*(n+1))/2;
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[0] = realloc((*figurateSet)[0], (96-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[0][a] = x;
        }
    }
    (*sizes)[0] = 96-remove;
    remove = 0;
    // square
    for (int n = 32, a = 0; n <= 99; n++, a++)
    {
        int x = n*n;
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[1] = realloc((*figurateSet)[1], (68-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[1][a] = x;
        }
    }
    (*sizes)[1] = 68-remove;
    remove = 0;
    // pentagonal
    for (int n = 26, a = 0; n <= 81; n++, a++)
    {
        int x = (int)(n*(3*n-1))/2;
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[2] = realloc((*figurateSet)[2], (56-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[2][a] = x;
        }
    }
    (*sizes)[2] = 56 - remove;
    remove = 0;
    // hexagonal
    for (int n = 23, a = 0; n <= 70; n++, a++)
    {
        int x = n*(2*n-1);
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[3] = realloc((*figurateSet)[3], (48-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[3][a] = x;
        }
    }
    (*sizes)[3] = 48-remove;
    remove = 0;
    // heptagonal
    for (int n = 21, a = 0; n <= 63; n++, a++)
    {
        int x = (int)(n*(5*n-3))/2;
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[4] = realloc((*figurateSet)[4], (43-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[4][a] = x;
        }
    }
    (*sizes)[4] = 43-remove;
    remove = 0;
    // octagonal
    for (int n = 19, a = 0; n <= 58; n++, a++)
    {
        int x = n*(3*n-2);
        if ((x % 100) < 10)
        {
            remove++;
            a--;
            (*figurateSet)[5] = realloc((*figurateSet)[5], (40-remove)*sizeof(int));
        }
        else
        {
            (*figurateSet)[5][a] = x;
        }
    }
    (*sizes)[5] = 40-remove;
}

bool isCyclical(int a, int b)
{
    return (a%100)==((int)(b/100));
}


bool orderedCyclicalSet(orderedPair *set, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        if (!isCyclical(set[i].y, set[i+1].y))
        {
            return false;
        }
    }
    if (!isCyclical(set[size-1].y, set[0].y))
    {
        return false;

    }
    return true;
}