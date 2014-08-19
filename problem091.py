#!/usr/bin/env python

from euler import gcd

n = 50
t = 0

for i in xrange(1, n+1):
    for j in xrange(1, n):
        m = gcd(i, j)
        t += min(i*m / j, m * (n-j) / i)

print t*2 + n*n*3

