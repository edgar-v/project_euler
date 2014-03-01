def palindrom(a):
    a = str(a)
    for i in range(0, len(a)):
        if a[i] != a[-i - 1]:
            return False
    return True

def main():
    best = 0
    for i in range(0, 1000):
        for j in range(i, 1000):
            product = i * j
            if palindrom(product) == True and product > best:
                best = product
    print(best)

main()
