#!/usr/bin/env python

base = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
extras = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

firstTwenty = 0
for i in range(1, len(base)):
    firstTwenty += len(base[i])
for i in range(0, len(extras)):
    firstTwenty += len(extras[i])

for i in range(20, 100):
    a = str(i)
    firstTwenty += len(base[int(a[1])]) + len(tens[int(a[0])])

for i in range(100, 1000):
    a = str(i)
    prev = firstTwenty
    if int(a[1]) == 1:
        firstTwenty += len(extras[int(a[2])]) + len(base[int(a[0])]) + 10
    else:
        firstTwenty += len(base[int(a[0])]) + 10 + len(tens[int(a[1])]) + len(base[int(a[2])])
    if i % 100 == 0:
        firstTwenty -= 3
firstTwenty += 11
print(firstTwenty)
