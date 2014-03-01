def main():
    fil = open("oppgave13.txt", "r")
    total = 0
    for i in range(0, 100):
        num = int(fil.readline())
        total += num
    string = str(total)
    print(string[:10])

main()
