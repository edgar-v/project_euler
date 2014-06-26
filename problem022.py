#!/usr/bin/env python

names = sorted(open("problem022.txt", "r").read:).split(","))
print sum([(i+1) * sum([ord(x) - 64 for x in names[i].replace("\"", "")]) for i in range(len(names))])
