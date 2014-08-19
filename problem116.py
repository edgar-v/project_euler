#!/usr/bin/env python

from fractions import Fraction

print sum([sum([reduce(lambda x, y: x*y, (Fraction(x + (50 - (i*x)) - j, j + 1) for j in range(x))) for x in range(1, int(50/i) + 1)]) for i in range(2, 5)])
