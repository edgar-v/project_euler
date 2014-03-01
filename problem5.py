def main():
    counter = 1
    while True:
        isOk = True
        for i in range(1, 20):
            if counter % i != 0:
                isOk = False
                break
        if isOk == True:
            print(counter)
            break
        counter += 1

main()
