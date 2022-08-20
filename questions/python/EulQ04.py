# Largest Palindrome Product

import timeit as t

def largest_palindrome_prod(digits):
    highestProd = 0
    min = 10 ** (digits - 1)
    max = (10 ** digits) - 1
    i = max
    while i >= min:
        j = max
        while j >= i:
            prod = i * j
            if prod < highestProd:
                break
            if isPalindrome(prod):
                highestProd = prod
            j -= 1
        i -= 1
    return highestProd

def isPalindrome(x):
    strx = str(x)
    if strx == strx[::-1]:
        return True
    return False

a = int(input())
start = t.default_timer()
print(largest_palindrome_prod(a)) 
end = t.default_timer()
print("Time elapsed:", end-start)
