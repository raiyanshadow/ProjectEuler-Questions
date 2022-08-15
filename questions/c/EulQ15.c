// Lattice paths

#include "essentials.c"

int main()
{
    int size;
    scanf("%i", &size);
    timeStart();

    bignum ret;
    choose(2*size, size, &ret);
    print_bignum(&ret);

    timeEnd();
}