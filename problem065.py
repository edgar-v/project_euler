#!/usr/bin/python
from fractions import Fraction
from decimal import *

f = []

for i in range(100):
    if i % 3 == 1:
        f.append((int(i/3) + 1) * 2)
    else:
        f.append(1)


target = 100


def fracts(count, target):
    if count == target - 2:
        return f[count], 1
    else:
        den, num = fracts(count + 1, target)
        num = f[count] * den + num
        return num, den
        

        


den, num = fracts(0, target)
num = 2 * den + num
snum = str(num)
tot = 0
for i in snum:
    tot += int(i)

print(num, "/", den)
print(tot)
