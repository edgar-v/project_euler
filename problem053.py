from math import factorial

total = 0

for i in range(1, 101):
    for j in range(1, i + 1):
        if (factorial(i)) / (factorial(j) * (factorial(i - j))) > 1000000:
            total += 1
print(total)
