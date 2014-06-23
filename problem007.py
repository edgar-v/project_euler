def main():
    numPrimes = 1
    counter = 3
    while numPrimes != 10001:
        isOk = True
        for i in range(2, counter):
            if counter % i == 0:
                isOk = False
                break
        if isOk == True:
            numPrimes += 1
            print(counter)
        counter += 1

main()
