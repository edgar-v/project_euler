#!/usr/bin/python
from math import sqrt

def match(n):
    s = str(n)
    return not all(int(s[x*2]) == x+1 for x in range(0, 9))
base = "1020304050607080900"
n = 1010101010
while match(n*n):

    s = list((str(n*n)))

    if int(s[2]) > 2:
        s[1] = str(int(s[1]) + 1)
        s = s[:2] + list(base[2:])
        n = int(sqrt(int("".join(s))))

    if int(s[4]) > 3:
        if int(s[3]) == 9:
            s[2] = str(int(s[2]) + 1)
            s[3] = "0"
        else:
            s[3] = str(int(s[3]) + 1)
            s = s[:4] + list(base[4:])
        n = int(sqrt(int("".join(s))))

    n += 2

print(n)
