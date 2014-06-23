def main():
    memo = []
    for i in range(0, 21):
        newGrid = []
        for j in range(0, 21):
            newGrid.append(-1)
        memo.append(newGrid)
    solutions = getSolution(0, 0, memo)
    print(solutions)
    memo[19][19] = "X"
    for i in range(0, 21):
        newStr = ""
        for j in range(0, 21):
            newStr += str(memo[j][i]) + ","
        print(newStr)

def getSolution(x, y, memo):
    solFromHere = 0
    if x < 20:
        if memo[x+1][y] != -1:
            solFromHere += memo[x+1][y]
        else:
            solutions = getSolution(x+1, y, memo)
            solFromHere += solutions
            memo[x+1][y] = solutions
    if y < 20:
        if memo[x][y+1] != -1:
            solFromHere += memo[x][y+1]
        else:
            solutions = getSolution(x, y+1, memo)
            solFromHere += solutions
            memo[x][y+1] = solutions
    if solFromHere == 0:
        return 1
    return solFromHere

main()

