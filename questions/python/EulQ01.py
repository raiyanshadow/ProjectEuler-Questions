# Multiple of 3 or 5

import timeit as t

def mult(x):
    return sum([i for i in range(x) if is_div_by_35(i)])

def is_div_by_35(x):
    return x % 3 == 0 or x % 5 == 0

a = int(input())

start = t.default_timer()
print(mult(a))
end = t.default_timer()
print('Time elapsed:', end-start)