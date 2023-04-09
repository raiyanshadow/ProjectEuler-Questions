// XOR decryption

#include "essentials.c"

char** commonWords = (char*[]) {"the\0", "The\0", "and\0", "An\0", "an\0"};

void viewMessage(int* vals, int len, char** keycombos, int perms);
void generatekeys(char **keycombos);
bool hasCommonWords(int* passage, int len);

int main()
{
    timeStart();
    char *fname = "../../testcases/EulQ59.txt";
    int chars = getLineLength(fname, ',', 1);
    int *numbers = calloc(chars, sizeof(int));
    FILE* f = fopen(fname, "r");
    int ch = fgetc(f);
    char *tmp = malloc(sizeof(char));
    tmp[0] = '\0';
    int i = 1;
    int j = 0;
    while (ch != EOF)
    { 
        if (ch == ',')
        {
            i = 1;
            numbers[j] = atoi(tmp);
            j++;
            tmp = realloc(tmp, sizeof(char));
            tmp[0] = '\0';
        }
        else
        {  
            i++;
            tmp = realloc(tmp, i * sizeof(char));
            tmp[i-2] = ch;
            tmp[i-1] = '\0';
        }
        ch = fgetc(f);
    }
    numbers[j] = atoi(tmp);
    fclose(f);
    free(tmp);
    int permutations = 26*26*26; 
    // since key is a 3 letter "word", the possibilities can be 26*26*26 = 26^3 combinations
    char **keycombos = malloc(permutations * sizeof(char*));
    for (int i = 0; i < permutations; i++)
    {
        keycombos[i] = malloc(4 * sizeof(char));
    }
    generatekeys(keycombos);
    findMessage(numbers, chars, keycombos, permutations);
    timeEnd();
    for (int i = 0; i < permutations; i++)
    {
        free(keycombos[i]);
    }
    free(keycombos);
    free(numbers);
}

void generatekeys(char **keycombos)
{
    int pos = 0;
    for (int i = 97; i <= 122; i++)
    {
        for (int j = 97; j <= 122; j++)
        {
            for (int k = 97; k <= 122; k++)
            {
                keycombos[pos][0] = (char)i;
                keycombos[pos][1] = (char)j;
                keycombos[pos][2] = (char)k;
                keycombos[pos][3] = '\0';
                pos++;
            }
        }
    }
}

bool hasCommonWords(int* passage, int len)
{
    int checks = 0;
    for (int i = 0; i < 5; i++)
    {
        int size = strlen(commonWords[i]);
        checks += noCharsSeenIn(commonWords[i], passage, len, size);
    }
    if (checks > 20) // arbritary value that worked
    {
        return true;
    }
    return false;
}

void findMessage(int* vals, int len, char **keycombos, int perms)
{
    int *tmp = calloc(len, sizeof(int));
    bool flag = true;
    for (int i = 0; i < perms; i++)
    {
        flag = true;
        memcpy(tmp, vals, len*sizeof(int));
        for (int j = 0; j < len; j++)
        {
            tmp[j] ^= keycombos[i][j%3];
            if (tmp[j] < 32 || tmp[j] > 126)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            if (hasCommonWords(tmp, len))
            {
                printf("Key found: %s\n", keycombos[i]);
                int ret = 0;
                for (int j = 0; j < len; j++)
                {
                    printf("%c", tmp[j]);
                    ret += tmp[j];
                }
                printf("\nSum: %i\n", ret);
                free(tmp);
                return;
            }
            else
            {
                continue;
            }
        }
    }
}
