#!/usr/bin/env python

i = 2
tall1 = 1
tall2 = 1
while len(str(tall2)) < 1000:
    tall2, tall1 = tall1 + tall2, tall2
    i += 1
print(i)

