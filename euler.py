#!/usr/bin/env python

import math

def sieve_of_E(n):
    """Generates all primes up to n and returns a list with True/False for each prime"""
    primes = [True] * n
    sqrtN = int(math.sqrt(n))
    for i in range(2, sqrtN):
        if primes[i] is True:
            for j in range(i**2, n, i):
                primes[j] = False
    return primes
    
def gcd(x, y):
    while x != y:
        if x > y:
            x = x - y
        else:
            y = y - x
    return x
