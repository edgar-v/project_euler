#!/usr/bin/env python

lengths = [-1] * 51

def findSolution(length):
    if lengths[length] != -1:
        return lengths[length]
    total = 0
    if length == 0:
        total = 1
    # Black
    if length >= 1:
        total += findSolution(length - 1)
    # Red
    if length >= 2:
        total += findSolution(length - 2)
    # Green
    if length >= 3:
        total += findSolution(length - 3)
    # Blue
    if length >= 4:
        total += findSolution(length - 4) 

    lengths[length] = total
    return total 

findSolution(50)
print lengths[50]
