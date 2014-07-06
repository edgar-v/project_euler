#!/usr/bin/python
from decimal import *
from math import sqrt
getcontext().prec = 110

tot = 0

for i in range(1, 101):
    if i != int(sqrt(i)) ** 2:
        for j in str(Decimal(i).sqrt()).split('.')[1][0:99]:
            tot += int(j)

        tot += int(str(Decimal(i).sqrt()).split('.')[0])

print(tot)
