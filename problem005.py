#!/usr/bin/env python

import math
step = 20 * 19 * 18 * 17
i = step
while True:
    correct = True
    for j in [11,12,13,14,15,16,17,18,19,20]:
        if i % j != 0:
            correct = False
            break
    if correct:
        break
    i += step   

print i
