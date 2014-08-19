#!/usr/bin/env python

from fractions import Fraction

for i in xrange(1000000000000, 1100000000000):
    prevBlues = 0
    numBlues = int(i / 2)
    uBound = i
    lBound = 0
    binSearch = 0

    while prevBlues != numBlues:
        binSearch += 1
        prob = Fraction(Fraction(numBlues, i) * Fraction(numBlues - 1, i-1))
        prevBlues = numBlues
        if prob == 0.5:
            print numBlues, "winrar"
        elif prob < 0.5:
            lBound = numBlues
            numBlues = int((uBound + numBlues) / 2)
        elif prob > 0.5:
            uBound = numBlues
            numBlues = int((lBound + numBlues) / 2)

    

