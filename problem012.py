#!/usr/bin/env python

import math
import operator

def triangle_number():
    """returns the next triangle number"""
    val = 1
    counter = 2
    while True:
        yield val
        val += counter
        counter += 1

def numDivisors(n):
    orign = n
    divisors = []
    counter = 2
    while counter < n:
        if n % counter == 0:
            divisors.append(counter)
            n /= counter
            counter = 2
        else:
            counter += 1
    divisors.append(n)
    #print orign, divisors

    divs =  reduce(operator.mul, [divisors.count(x) + 1 for x in set(divisors)])
    #print "tot: %s" % divs
    return divs

gen = triangle_number()

maxdivs = 1
while True:
    val = gen.next()
    divs = numDivisors(val)

    if divs > maxdivs:
        maxdivs = divs
    if maxdivs > 500:
        print(val)
        break
