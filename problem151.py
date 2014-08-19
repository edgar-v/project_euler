#!/usr/bin/env python

paperMap = {}

def recurse(paper):

    ways = 0
    total = 0

    if paper[0] + paper[1] + paper[2] + paper[3] == 1:
        if paper[3] == 1:
            return 1, 0
        total += 1

    choices = [i for i in range(4) for x in range(paper[i])]
    for i in choices:
        newPaper = [x for x in paper]
        pick = i
        while pick < 3:
            newPaper[pick] -= 1
            newPaper[pick+1] += 2
            pick += 1
        newPaper[3] -= 1
        paperString = ''.join(str(x) for x in newPaper)
        if paperString in paperMap:
            ways += paperMap[paperString][0]
            total += paperMap[paperString][1]
        else:
            a, b = recurse(newPaper)
            paperMap[paperString] = (a, b)
            ways += a 
            total += b
    return ways, total

a, b = recurse([1,1,1,1])
print a, b

print float(b) / a
print float(a) / b
