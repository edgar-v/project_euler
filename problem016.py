def main():
    num = 2 ** 1000
    num = str(num)
    total = 0
    for i in range(0, len(num)):
        total += int(num[i])
    print(total)

main()