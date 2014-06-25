#!/usr/bin/env python

import math

table = {}

def compute_length(i):

    if i == 1:
        return 1

    if i in table:
        return table[i]

    l = 0
    if i % 2 == 0:
        l = compute_length(i / 2) + 1
    else:
        l = compute_length(3 * i + 1) + 1
    table[i] = l
    return l

longest = 1

for i in range(2,1000001):
    if i in table:
        longest = max(longest, table[i])
    else:
        length = compute_length(i)
        longest = max(longest, length)

print longest
    
