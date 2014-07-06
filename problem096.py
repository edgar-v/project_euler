#!/usr/bin/python

board =[[1,0,0,0,0,6,0,0,0],
        [0,2,0,0,5,0,0,0,0],
        [0,0,3,4,0,0,0,0,8],
        [0,0,0,0,0,7,1,0,5],
        [9,0,0,0,4,0,0,0,6],
        [8,0,4,5,0,0,0,0,0],
        [6,0,0,0,0,1,9,0,0],
        [0,0,0,0,2,0,0,5,0],
        [0,0,0,3,0,0,0,0,7]]

fullSet = {1,2,3,4,5,6,7,8,9}

def nSquares(row, column):
    xc = int(row / 3) * 3
    yc = int(column / 3) * 3
    square = [board[x][y] for x in range(xc, xc + 3) for y in range(yc, yc + 3)]
    return square

def nRow(row):
    return board[row]

def nColumns(column):
    return [board[x][column] for x in range(len(board))]

def logicalSolve():
    global board
    status = False
    
    for i in range(0, len(board)):
        for j in range(0, len(board)):
            if board[i][j] != 0:
                continue
            pos = nSquares(i, j) + nRow(i) + nColumns(j)
            posibilities = set(pos)
            posibilities.discard(0)
            if len(fullSet - posibilities) == 1:
                print(i, j, fullSet - posibilities)
                board[i][j] = (fullSet - posibilities).pop()
                status = True

    return status

for i in board:
    print(i)
print("---------")

while logicalSolve():
    print("---------")
    for i in board:
        print(i)
    print("---------")

print("----------")
for i in board:
    print(i)

