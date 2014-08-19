#!/usr/bin/env python

import itertools

digits = ('1','2','3','4')
symbols = ('+', '-', '*', '/')

symb_perm = []
for i in symbols:
    for j in symbols:
        for k in symbols:
            symb_perm.append((i, j, k))


perms = set()
for i in symb_perm:
    full_perm = list(itertools.permutations(i + digits))
    for j in full_perm:
        if j[0].isdigit() and j[1].isdigit():
            perms.add(''.join(j))

sums = set()
for perm in perms:
    total = 0
    per = list(perm)
    for i in range(3):
        op1 = next(i for i in range(len(per)) if per[i] in symbols)
        if op1 < 2:
            break
        if per[op1] == '+':
            per = per[:op1-2] + [str(float(per[op1-2]) + float(per[op1-1]))] + per[op1+1:]
        elif per[op1] == '-':
            per = per[:op1-2] + [str(float(per[op1-2]) - float(per[op1-1]))] + per[op1+1:]
        elif per[op1] == '*':
            per = per[:op1-2] + [str(float(per[op1-2]) * float(per[op1-1]))] + per[op1+1:]
        elif per[op1] == '/':
            if per[op1-2] == '0.0' or per[op1-1] == '0.0':
                break
            per = per[:op1-2] + [str(float(per[op1-2]) / float(per[op1-1]))] + per[op1+1:]
    if len(per) == 1 and float(per[0]).is_integer():
        sums.add(int(float(per[0])))


print sums
