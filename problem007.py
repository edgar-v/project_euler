#!/usr/bin/env python

import euler

primes = euler.sieve_of_E(1000000)

counter = 0
for i in range(2, len(primes)):
    if primes[i] is True:
        counter += 1
        if counter == 10001:
            print i
