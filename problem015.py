#!/usr/bin/env python

from fractions import Fraction

print reduce(lambda x,y: x*y, (Fraction(40 - i, i + 1) for i in xrange(20)))

