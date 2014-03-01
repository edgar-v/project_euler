from math import log10

total = 0

nom = 3
den = 2

for i in range(0, 1000):
    nom += den * 2
    den = nom - den
    if (int(log10(nom)) > int(log10(den))):
        total += 1

print(total)
