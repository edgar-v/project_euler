i = 2
tall1 = 1
tall2 = 1
while len(str(tall2)) < 1000:
    temp = tall2
    tall2 = tall1 + tall2
    tall1 = temp
    i += 1
print(i)
