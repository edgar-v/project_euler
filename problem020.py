#!/usr/bin/env python

print sum([int(x) for x in str(reduce(lambda x,y : x*y, [x for x in range(1,101)]))])
