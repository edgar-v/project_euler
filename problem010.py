#!/usr/bin/env python

import euler

primes = euler.sieve_of_E(2000000)

print sum([x for x in range(2, len(primes)) if primes[x] == True])
