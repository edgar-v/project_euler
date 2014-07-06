#!/usr/bin/env python

day_index = 0
sundays = 0

for i in range(0, 101):
    for j in range(1, 13):
        if day_index == 6 and i != 0:
            sundays += 1
        
        if j in [1,3,5,7,8,10,12]:
            day_index += 31
        elif j in [4,6,9,11]:
            day_index += 30
        elif i % 4 == 0 and i + 1900 % 400 == 0:
            day_index += 29
        else:
            day_index += 28
        day_index = day_index % 7

print(sundays)
        

