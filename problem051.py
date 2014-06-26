#!/usr/bin/env python

import math
import itertools

def generatePatterns(n):
    patterns = []
    seen = set()
    pattern = [True]*3  # True if it is a repeated number
    for i in range(n-4):
        pattern.append(False)
    permutations = itertools.permutations(pattern)
    for perm in permutations:
        if perm in seen:
            continue
        seen.add(perm)

    for i in seen:
        pat = list(i)
        pat.append(False)
        patterns.append(pat)
    return patterns

def sieve(n):
    squareN = int(math.sqrt(n))
    primes = [True] * n

    for i in range(2, squareN):
        if primes[i] == True:
            for j in range(pow(i, 2), n, i):
                primes[j] = False
    return primes

length = 999999

primes = sieve(length * 10)
primes = primes[1:]

print "sieve completed"

currentNumber = 10000
currentNumberString = str(currentNumber)

pattern = generatePatterns(6)

while True:
    if primes[currentNumber] is False:
        currentNumber = i
        currentNumberString = str(currentNumber)
        continue

         
