from math import pow

total = 0

for xBase in range(1, 100):
    for aPower in range(1, 30):
        test = int(pow(xBase, aPower))
        testLen = len(str(test))
        if testLen == aPower:
            total += 1
        if testLen > aPower:
            break 

print(total)
