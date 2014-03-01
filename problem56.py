maxTot = 0

for i in range(1, 101):
    for j in range(1, 101):
        number = i ** j
        numStr = str(number)
        total = 0
        for ch in numStr:
            total += int(ch)
            if total > maxTot:
                maxTot = total

print(maxTot)
