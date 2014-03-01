def main():
    num = 100
    tot = 1
    total = 0
    for i in range(1, 101):
        tot *= i
    string = str(tot)
    for i in range(0, len(string)):
        total += int(string[i])
    print(total)
main()
