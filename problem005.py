#!/usr/bin/env python

i = 20
while True:
    correct = True
    for j in range(3, 21):
        if i % j != 0:
            correct = False
            break
    if correct:
        break
    i += 20

print i
