#!/usr/bin/env python

fil = open("problem018.txt", "r")

triangle = []
numLines = 0
for line in fil:
    numbers = line.split()
    for i in range(0, len(numbers)):
        triangle.append(int(numbers[i]))
    numLines += 1

currentLine = numLines - 1
index = -numLines -1
for i in range(0, numLines):
    for j in range(0, currentLine):
        num = triangle[index - j]
        print(triangle[index - j + currentLine], triangle[index - j + currentLine + 1], num)
        triangle[index - j] += max(triangle[index -j + currentLine], triangle[index - j + currentLine + 1])
    index -= currentLine
    currentLine -= 1

print(triangle[0])
