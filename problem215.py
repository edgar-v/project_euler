#!/usr/bin/env python

length = 32
rows = []

mem = {}

def generate_rows(row):
    global rows
    if row[-1] > length:
        return
    if row[-1] == length:
        rows.append(row)
    if row[-1] < length:
        generate_rows(list(row) + [row[-1] + 2])
        generate_rows(list(row) + [row[-1] + 3])

generate_rows([0,2])
generate_rows([0,3])

centerRow = [x[1:-1] for x in rows]

combinations = [0] * len(centerRow)

a = [[row, y] for row in centerRow for y in centerRow if len([True for x in row if x not in y]) == len(row)]
for i in a:
    print i

for i in rows:
    print i
    
