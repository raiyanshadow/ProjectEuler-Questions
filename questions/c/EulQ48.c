// Self powers
#include "essentials.c"

// We can easily solve this problem using modular exponentiation
// We want to find the last 10 digits of the end result, which is equal to number % 1e10
// We know that (ab) mod p = ((a mod p) * (b mod p)) mod p
// So (n^n) mod p = (...(((((n mod p) * (n mod p)) mod p * ... )...)) * (n mod p)) mod p) mod p
// Using a product series, everytime we multiply n by itself, we check the modulus of it
// So then we can take the product series of our self power sum and utilize modular exponentiation to correct any overflow issues

long long solveSeries(int n, long long modMax);

int main()
{
    int x, upto;
    scanf("%i %i", &x, &upto);
    timeStart();
    
    long long modMax = (long long)pow(10, upto);
    long long ret = solveSeries(x, modMax);
    printf("%lli\n", ret);

    /* Using bignum, result comes after 145 seconds :p 

        bignum ret;
        initialize_bignum(&ret);
        for (int i = 1; i <= x; i++)
        {
            bignum power = bignum_pow(i, i);
            bignum add;
            copy_bignum(&ret, &add);
            add_bignum(&power, &add, &ret);
        }
        if (upto > ret.lastdigit)
        {
            printf("Invalid digit range\n");
            return -1;
        }
        char* lastDigits = (char *) calloc(upto, sizeof(char));
        for (int i = 0; i < upto; i++)
        {
            lastDigits[i] = ret.digits[i];
        }

        for (int i = upto - 1; i >= 0; i--)
        {
            printf("%c", '0'+lastDigits[i]);
        }
        printf("\n");
        free(lastDigits);
    */

    timeEnd();
}

long long solveSeries(int n, long long m)
{
    long long ret = 0;

    // Our self power series containing the product series of n^n mod m
    // In latex math: \sum_{i = 1}^{n}(\prod_{j = 1}^{i}(j)\mod m)\mod m \mathbf{\ ,\forall m \ \epsilon \ \mathbb{Z}^{+}\ }
    for (int i = 1; i <= n; i++)
    {
        long long tmp = i;

        // Modular power series
        for (int j = 1; j < i; j++)
        {
            tmp *= i;
            
            // This handles any overflow whenever tmp > (10 ^ numDigits) where numDigits is 10 in this problem
            // We only care about the last n digits of the end result
            tmp %= m;
        }
        ret += tmp;
        // Again to handle overflow, since we only care about the last n digits of the end result
        ret %= m;
    }
    return ret;
}