# Smallest multiple
import timeit as t
from math import lcm

max = int(input())
start = t.default_timer()
list = [i for i in range(2, max)]
ret = 1

for i in list:
    ret = lcm(ret, i)

print(ret)

end = t.default_timer()
print("Time elapsed:", end-start)


