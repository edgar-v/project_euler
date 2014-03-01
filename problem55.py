total = 0

ab = []
for i in range(0, 10000):
    ab.append(False)

for i in range(0, 10000):
    number = i
    partNums = []
    for j in range(0, 50):
        strNum = str(number)
        revNum = strNum[::-1]
        number = int(strNum) + int(revNum)
        palNum = str(number)
        partNums.append(int(palNum))
        isGood = True
        for k in range(0, len(palNum) / 2):
            if palNum[k] != palNum[len(palNum) - k - 1]:
                isGood = False
                break
        if isGood:
            total += 1
            break
print(10000 - total)


