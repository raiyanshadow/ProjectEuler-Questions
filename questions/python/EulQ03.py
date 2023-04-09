# Largest prime factor

import timeit as t
import math as m

def highest_prime_fac(x):
    i = 2
    factors = []
    while i * i <= x:
        if x % i:
            i += 1
        else:
            x //= i
            factors.append(i)
    factors.append(x)
    return factors

a = int(input())
start = t.default_timer()
highest_prime = highest_prime_fac(a)
highest_prime = highest_prime[-1]
print(highest_prime) 
end = t.default_timer()
print("Time elapsed:", end-start)