#!/usr/bin/python
f = open("problem099.txt")
lines = f.readlines()

best = 0
bestLine = 1
for i in range(0, len(lines)):
    nums = lines[i].strip().split(',')
    newVal = int(nums[0]) + int(nums[1]) * 1.5
    if newVal > best:
        best = newVal
        print(newVal, nums[0], nums[1])
        bestLine = i + 1
    if i == 708:
        print("708: ",newVal, nums[0], nums[1])

print(bestLine)

f.close()

