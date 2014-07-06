#!/usr/bin/env python

print next(a*b*(1000-a-b) for a in range(1,1000) for b in range(1, 1000) if (1000-a-b)**2 == (a**2 + b**2))
