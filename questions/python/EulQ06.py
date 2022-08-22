# Sum square difference
import timeit as t

def sum_square_difference(x):
    return (((x * (x + 1)) / 2) ** 2) - ((x * (x + 1) * ((2 * x) + 1)) / 6) 

a = int(input())

start = t.default_timer()

print(sum_square_difference(a))

end = t.default_timer()
print("Elapsed time:", end-start)