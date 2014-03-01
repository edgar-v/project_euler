def summ():
    total = 0
    nums = 0
    for i in range(0, 1000):
        if i % 3 == 0 or i % 5 == 0:
            total += i
            nums += 1
    print(nums)
    return total

print(summ())
