def func():
    num = 600851475143 
    top = 775147
    best = 0
    for i in range(1, top + 1):
        if num % i == 0:
            if prime(i) == True:
               best = i
    return best

def prime(a):
    for i in range(2, a):
        if a % i == 0:
            return False
    
    return True

print(prime(17))
print(prime(8))
print(prime(37))
print(func())
