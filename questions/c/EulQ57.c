// Square root convergence

#include "essentials.c"

int main()
{
    timeStart();

    bignum n1, n2, n3, m1, m2, m3, two;
    int_to_bignum(1, &n1);
    int_to_bignum(3, &n2);
    int_to_bignum(0, &n3);
    int_to_bignum(2, &two);

    int_to_bignum(1, &m1);
    int_to_bignum(2, &m2);
    int_to_bignum(0, &m3);

    int count = 0;
    for (int i = 0; i < 999; i++)
    {
        bignum tmp_n, tmp_m;
        copy_bignum(&n2, &tmp_n);
        bignum mult_tmp;
        multiply_bignum(&two, &tmp_n, &mult_tmp);
        add_bignum(&mult_tmp, &n1, &n3);
        copy_bignum(&tmp_n, &n1);
        copy_bignum(&n3, &n2);
        copy_bignum(&m2, &tmp_m);
        multiply_bignum(&two, &tmp_m, &mult_tmp);
        add_bignum(&mult_tmp, &m1, &m3);
        copy_bignum(&tmp_m, &m1);
        copy_bignum(&m3, &m2);
        if (n3.lastdigit > m3.lastdigit)
        {
            count++;
        }
    }

    printf("%i\n", count);

    timeEnd();
}