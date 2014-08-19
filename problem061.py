#!/usr/bin/env python


formulas = [lambda n: (n * (n+1)) / 2, lambda n: n**2, lambda n: (n * (3*n -1)) / 2, lambda n: n*((2*n) - 1), lambda n: (n * (5*n -3)) / 2, lambda n: n* ((3*n) - 2)]

nums = [[str(f(n)) for n in range(500) if f(n) >= 1000 and f(n) < 10000] for f in formulas]

def find_cycle(num, index, used, sol):
    if index == 6:
        if sol[0][:2] == sol[-1][2:]:
            print sum(int(x) for x in sol)
            exit()
    for j in range(len(used)):
        if used[j] == 1:
            continue
        for i in nums[j]:
            if num[2:] == i[:2]:
                newUsed = [x for x in used]
                newUsed[j] = 1
                res = find_cycle(i, index + 1, newUsed, sol + [num])

for num in nums[5]:
    if num != '1281':
        continue
    find_cycle(num, 0, [0,0,0,0,0,0], [])
