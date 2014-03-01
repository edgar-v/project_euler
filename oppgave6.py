def squares():
    total = 0
    for i in range(0, 101):
        total += i ** 2
    return total

def squaresum():
    total = 0
    for i in range(0, 101):
        total += i
    return total ** 2

print(squaresum() - squares())
