// Poker hands
// least fun challenge by far 
// ~6 hours to complete :P

#include "essentials.c"

int cards[] = {0, 0, 0, 0, 0};

void deepFree(char ***arr, int rows, int cols);
void write(char ***p1, char ***p2, char *fname);
int findWinner(char **hand1, char **hand2);
int determineFlush(char **hand, int straight);
orderedPair findPairs(char **hand);
orderedPair findKinds(char **hand);
int isStraight(char **hand);
orderedPair fullHouse(char **hand, orderedPair kind);
int cardVal(char ch);

int main()
{
    timeStart();
    char *fname = "../../testcases/EulQ54.txt";
    int deals = getFileLines(fname);
    char ***p1 = (char ***)calloc(deals, sizeof(char **));
    char ***p2 = (char ***)calloc(deals, sizeof(char **));
    for (int i = 0; i < deals; i++)
    {
        p1[i] = (char **)calloc(5, sizeof(char *));
        p2[i] = (char **)calloc(5, sizeof(char *));
        for (int j = 0; j < 5; j++)
        {
            p1[i][j] = (char *)calloc(2, sizeof(char));
            p2[i][j] = (char *)calloc(2, sizeof(char));
        }
    }

    write(p1, p2, fname);

    int p1Wins = 0;
    for (int i = 0; i < deals; i++)
    {
        if (findWinner(p1[i], p2[i]) == 1)
        {
            p1Wins++;
        }
    }
    printf("%i\n", p1Wins);

    deepFree(p1, deals, 5);
    deepFree(p2, deals, 5);
    timeEnd();
}

void deepFree(char ***arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}

void write(char ***p1, char ***p2, char *fname)
{
    FILE *f = fopen(fname, "r");
    int ch = fgetc(f);
    int rowTrack = 0;
    int colTrack = 0;
    int chTrack = 0;
    while (ch != EOF)
    {
        if (ch == ' ')
        {
            chTrack = 0;
            colTrack++;
            ch = fgetc(f);
            continue;
        }

        if (ch == '\n')
        {
            chTrack = 0;
            rowTrack++;
            colTrack = 0;
        }

        else
        {
            if (colTrack > 4)
            {
                p2[rowTrack][colTrack % 5][chTrack] = (char)ch;
            }
            else
            {
                p1[rowTrack][colTrack][chTrack] = (char)ch;
            }
            chTrack++;
        }
        ch = fgetc(f);
    }

    fclose(f);
}

int findWinner(char **hand1, char **hand2)
{
    int hc1 = 0, hc2 = 0;
    int val1 = 0, val2 = 0;
    for (int i = 0; i < 5; i++)
    {
        int a1 = cardVal(hand1[i][0]);
        int a2 = cardVal(hand2[i][0]);
        
        hc1 = MAX(hc1, a1);
        hc2 = MAX(hc2, a2);
    }
    
    int s1 = isStraight(hand1);                                         // 0 if not straight
    int s2 = isStraight(hand2);
    int f1 = determineFlush(hand1, s1);                                 // 0 if no flush
    int f2 = determineFlush(hand2, s2); 
    orderedPair p1 = findPairs(hand1);                                  // p1.x = pair type, p1.y = pair value, both 0 if no pairs
    orderedPair p2 = findPairs(hand2);
    orderedPair k1 = findKinds(hand1);                                  // k1.x = kind type, k1.y = kind value, both 0 if no kinds
    orderedPair k2 = findKinds(hand2);
    orderedPair fh1 = fullHouse(hand1, k1);                             // fh1.x = 0 if not full house, fh1.y = threes value
    orderedPair fh2 = fullHouse(hand2, k2);

    int p1HandType = MAX(fh1.x, MAX(k1.x, MAX(p1.x, MAX(s1, f1))));
    int p2HandType = MAX(fh2.x, MAX(k2.x, MAX(p2.x, MAX(s1, f1))));
    int ret = 0;

    // so cool right, just a bunch of very well put together if statements
    if (f1 > f2 && f1 == 10)
    {
        return 1;
    }
    else if (f1 < f2 && f2 == 10)
    {
        return 0;
    }
    if (f1 > f2 && f1 == 9)
    {
        return 1;
    }
    else if (f1 < f2 && f2 == 9)
    {
        return 0;
    }
    if (k1.y > k2.y && k1.x == 8)
    {
        return 1;
    }
    else if (k1.y < k2.y && k2.x == 8)
    {
        return 0;
    }
    if (fh1.y > fh2.y && fh1.x == 7)
    {
        return 1;
    }
    else if (fh1.y < fh2.y && fh2.x == 7)
    {
        return 0;
    }
    if (f1 > f2 && f1 == 6)
    {
        return 1;
    }
    else if (f1 < f2 && f2 == 6)
    {
        return 0;
    }
    if (s1 > s2 && s1 == 5)
    {
        return 1;
    }
    else if (s1 < s2 && s2 == 5)
    {
        return 0;
    }
    if (k1.x > k2.x && k1.x == 4)
    {
        return 1;
    }
    else if (k1.x < k2.x && k2.x == 4)
    {
        return 0;
    }
    if (p1.x > p2.x && p1.x == 3)
    {
        return 1;
    }
    else if (p1.x < p2.x && p2.x == 3)
    {
        return 0;
    }
    if (p1.y > p2.y && p1.x == 2)
    {
        return 1;
    }
    else if (p1.y < p2.y && p2.x == 2)
    {
        return 0;
    }
    if (hc1 > hc2)
    {
        return 1;
    }
    else if (hc1 < hc2)
    {
        return 0;
    }
    while (hc1 == hc2)
    {
        if (hc1 > hc2)
        {
            printf("%i > %i\n", hc1, hc2);
            return 1;
        }
        else if (hc1 < hc2)
        {
            printf("%i < %i\n", hc1, hc2);
            return 0;
        }
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i = 0; i < 5; i++)
        {
            int a = cardVal(hand1[i][0]);
            int b = cardVal(hand2[i][0]);
            if (a < hc1)
            {
                tmp1 = MAX(a, tmp1);
            }
            if (b < hc2)
            {
                tmp2 = MAX(b, tmp2);
            }
        }
        hc1 = tmp1;
        hc2 = tmp2;
    }

    return 0;
}

int determineFlush(char **hand, int straight)
{
    char *suit = (char*)calloc(5, sizeof(char));
    int a = 100;
    for (int i = 0; i < 5; i++)
    {
        a = MIN(a, cardVal(hand[i][0]));
        suit[i] = hand[i][1];
    }

    for (int i = 0; i < 4; i++)
    {
        if (suit[i] != suit[i+1])
        {
            free(suit);
            return 0;
        }
    }

    free(suit);

    if (straight == 5)
    {
        if (a == 10)
        {
            return 10;
        }
        else
        {
            return 9;
        }
    }
    return 6;
}

orderedPair findPairs(char **hand)
{
    orderedPair ret = makePair(0, 0);
    int same = 0;
    int lastPair = 0;
    int pair = 0;

    for (int i = 0; i < 4; i++)
    {
        int a = cardVal(hand[i][0]);
        if (a != lastPair)
        {
            for (int j = i + 1; j < 5; j++)
            {
                int b = cardVal(hand[j][0]);
                if (a == b)
                {
                    lastPair = MAX(lastPair, a);
                    pair++;
                    break;
                }
            }
        }
        if (pair == 2)
        {
            break;
        }
    }

    ret.x = pair + 1;
    ret.y = lastPair;

    return ret;
}

orderedPair findKinds(char **hand)
{
    orderedPair ret = makePair(0, 0);
    int kindVal = 0;
    int kindType = 0;

    for (int i = 0; i < 4; i++)
    {
        kindType = 0;
        int a = cardVal(hand[i][0]);
        for (int j = i + 1; j < 5; j++)
        {
            int b = cardVal(hand[j][0]);
            if (a == b)
            {
                kindVal = a;
                kindType++;
                if (kindType == 3)
                {
                    break;
                }
            }
        }
        if (kindType >= 2)
        {
            break;
        }
    }

    int type = 0;
    switch (kindType)
    {
        case 1:
            type = 0;
            break;
        case 2:
            type = 4;
            break;
        case 3:
            type = 8;
            break;
        default:
            break;
    }

    ret.x = type;
    ret.y = kindVal;

    return ret;
}

int isStraight(char **hand)
{
    bool ret = true;
    int i = 0;
    int *sortedHand = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        sortedHand[i] = cardVal(hand[i][0]);
    }
    qsort(sortedHand, 5, sizeof(int), cmpfunc);
    while (ret && i < 4)
    {
        if (sortedHand[i + 1] - sortedHand[i] == 1)
        {
            i++;
            ret = true;
            continue;
        }
        ret = false;
    }
    free(sortedHand);
    int val = (ret == true) ? 5 : 0;
    return val;
}

orderedPair fullHouse(char **hand, orderedPair kind)
{
    orderedPair ret = makePair(0, 0);

    if (kind.x != 4)
    {
        return ret;
    }
    for (int i = 0; i < 4; i++)
    {
        int a = cardVal(hand[i][0]);
        if (a != kind.y)
        {
            for (int j = i + 1; j < 5; j++)
            {
                int b = cardVal(hand[j][0]);
                if (b == a)
                {
                    ret.x = 7;
                    ret.y = kind.y;
                    return ret;
                } 
            }
        }
    }

    return ret;
}

int cardVal(char ch)
{
    int a = 0;
    switch (ch)
    {
        case 'T':
            a = 10;
            break;
        case 'J':
            a = 11;
            break;
        case 'Q':
            a = 12;
            break;
        case 'K':
            a = 13;
            break;
        case 'A':
            a = 14;
            break;
        default:
            break;
    }
    if (a > 9)
    {
        return a;
    }
    return ch - '0';
}