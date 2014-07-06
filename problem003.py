#!/usr/bin/env python

num = 600851475143
counter = 2

while num > 1:
    while counter < num:
        if num % counter == 0:
            num /= counter
            counter = 2
            break
        else:
            counter += 1
    if counter == num:
        print num
        break
