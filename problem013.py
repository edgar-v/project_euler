#!/usr/bin/env python

print str(sum([int(x) for x in open("problem013.txt", "r").read().split("\n") if x is not ""]))[0:10]
