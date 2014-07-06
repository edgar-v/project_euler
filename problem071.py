from fractions import Fraction
from decimal import *
from math import sqrt
from time import sleep

def gcd(a, b):
    if b == a:
        return a
    elif a > b:
        return gcd(a - b, b)
    else:
        return gcd(a, b - a)

fractions = []


for i in range(2, 1000001): # denominator
    for j in range(1, i): # numerator
        a, b = i, j
        print(a, b)
        d = gcd(a, b)
        a, b = a/d, b/d

