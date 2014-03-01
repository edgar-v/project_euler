import time
fil = open("oppgave81.txt", "r")
matrix = []
newline = fil.readline()
while newline != "":
    newline = newline.replace(","," ")
    matrix.append(newline.split())
    newline = fil.readline()

minMatrix = []
for i in range(0, len(matrix[0])):
    newRow = []
    for j in range(0, len(matrix)):
        newRow.append(-1)
        matrix[i][j] = int(matrix[i][j])
    minMatrix.append(newRow)

def findMinCostFrom(x, y):
    min_sum = matrix[x][y]
    sum1 = -1
    sum2 = -1
    if x < len(matrix) - 1 and minMatrix[x + 1][y] != -1:
        sum1 = minMatrix[x + 1][y] 
    elif x < len(matrix) - 1:
        sum1 = findMinCostFrom(x + 1, y)
        minMatrix[x + 1][y] = sum1

    if y < len(matrix) - 1 and minMatrix[x][y + 1] != -1:
        sum2 = minMatrix[x][y + 1]
    elif y < len(matrix) - 1:
        sum2 = findMinCostFrom(x, y + 1)
        minMatrix[x][y + 1] = sum2
    
    if sum1 == -1 and sum2 != -1:
        min_sum += sum2
    elif sum2 == -1 and sum1 != -1:
        min_sum += sum1
    elif sum1 != -1 and sum2 != -1:
        min_sum += min(sum1, sum2)
    return min_sum

minCost = findMinCostFrom(0, 0)
print(minCost)

