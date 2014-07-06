#!/usr/bin/env python

def func():
    a = 1
    b = 2
    total = 2
    while b < 4000000:
        temp = a
        a = b
        b = temp + a
        if b % 2 == 0:
            total += b
    return total

print(func())

