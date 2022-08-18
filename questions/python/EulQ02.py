# Even Fibonacci numbers

import timeit as t
from itertools import takewhile

def fib():
    a = 0
    b = 1
    c = 0
    while True:
        yield a
        a = b
        b = c + b
        c = a

def even_fib_sum(x):
    fibs = filter(lambda x: x % 2 == 0, fib())
    return sum(list(takewhile(lambda n: n < x, fibs)))

a = int(input())

start = t.default_timer()
print(even_fib_sum(a))

end = t.default_timer()
print("Time elapsed:", end-start)