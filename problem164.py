#!/usr/bin/env python

mem = [[[-1 for i in range(10)] for j in range(10)] for k in range(21)]

def generate(num):
    if len(num) == 20:
        return 1
    if len(num) >= 2 and mem[len(num)][num[-1]][num[-2]] != -1:
        return mem[len(num)][num[-1]][num[-2]]

    total = 0

    if len(num) == 1:
        for i in range(0, 10 - num[0]):
            total += generate(list(num) + [i])
    else:
        for i in range(0, 10 - (num[-1] + num[-2])):
            total += generate(list(num) + [i])

    if len(num) >= 2:
        mem[len(num)][num[-1]][num[-2]] = total
    return total

print sum([generate([i]) for i in range(1, 10)])

