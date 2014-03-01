def main():
    a = open("oppgave11.txt", "r")
    b = a.read()
    table = b.split(" ")
    table[-1] = '48'
    tot = 0

    for i in range(0, len(table)):
        table[i] = int(table[i])
    print(table)
    t = tot
    p = 0
    for i in range(0, len(table)):
        t = tot
        if i - 60 >= 0:
            tot = max(tot, table[i] * table[i-20] * table[i - 40] * table[i - 60])
        if i - 57 >= 0 and i % 20 <= 16:
           tot = max(tot, table[i] * table[i-19] * table[i-38] * table[i-57])
        if i + 3 < len(table) and i % 20 <= 16:
            tot = max(tot, table[i] * table[i+1] * table[i+2] * table[i+3])
        if i + 63 < len(table) and i % 20 <= 16:
            tot = max(tot, table[i] * table[i+21] * table[i+42] * table[i+63])
        if tot != t:
            print(i, table[i], tot)
    print(tot)
main()
