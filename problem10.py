import time

def main():
    total = 2
    a = [2]
    counter = 0
    for i in range(3, 2000001):
        isOk = True
        for j in range(0, len(a)):
            if i % a[j] == 0:
                isOk = False
                break
        if isOk == True:
            counter += 1
            if counter % 1000 == 0:
                print(i)
            a.append(i)
            total += i
    print(total)

main()
