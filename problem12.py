import time
import math

def main():
    counter = 2
    maxdivs = 1
    val = 1
    while True:
        val += counter
        divs = 0
        for i in range(2, int(math.sqrt(val)) + 1):
            if counter % i == 0:
                divs += 1
        if divs > maxdivs:
            print(divs, counter, val)
            maxdivs = divs
        if divs > 500:
            print(val, counter)
            break
        counter += 1

main()
