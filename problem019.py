import time
day_index = 0
sundays = 0

for i in range(0, 101):
    for j in range(1, 13):
        if day_index == 6 and i != 0:
            sundays += 1
        
        if j == 1 or j == 3 or j == 5 or j == 7 or j == 8 or j == 10 or j == 12:
            day_index += 31
        elif j == 4 or j == 6 or j == 9 or j == 11:
            day_index += 30
        elif i % 4 == 0 and i + 1900 % 400 == 0:
            day_index += 29
        else:
            day_index += 28
        day_index = day_index % 7

print(sundays)
        

