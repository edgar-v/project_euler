#!/usr/bin/env python


nums = [0] * 4

poss = 0

def rec(level, tot):
    global poss
    if sum(nums) > tot or (sum(nums) + 9 < tot and level == 3):
        return
    if level < 3:
        for i in range(10):
            nums[level] = i
            rec(level + 1, tot)
    else:
        for i in range(min(tot - sum(nums) + 1, 10)):
            nums[level] = i
            poss += 1
    nums[level] = 0
    return

for i in range(0, 36):
    rec(0, i)
print poss
