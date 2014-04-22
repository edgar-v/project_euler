#!/usr/bin/python2

import sys

def fib():
    fn1 = 1
    fn2 = 1
    k = 2
    while True:
        k += 1
        fn2, fn1 = fn1 + fn2, fn2
        yield fn2, k

def pandigital(num):
    strnum = str(num)
    digits = [False]*10
    for c in strnum:
        digits[int(c)] = True
    pandigital = True
    digits = digits[1:]
    for n in digits:
        if n is False:
            pandigital = False
            break
    if pandigital:
        return True
    else:
        return False

tailcut = 1000000000

n = 2
found = False

fibGen = fib()

while not found:
    n += 1
    fn, k = fibGen.next()
    fn = fn % tailcut

    if pandigital(fn):
        t = n * 0.20898764024997873 - 0.3494850021680094
        if pandigital(int(10 ** (t - int(t) + 8))):
            found = True

print n, fn
