#!/usr/bin/env python

import random
import fractions

from multiprocessing import Process, Queue, Pool
from ctypes import c_int

# Solve by simulation

num_games = 15
num_wins = 0
num_simulations = 10000000
num_processors = 8

def worker(start):
    blues = 0
    numsims = num_simulations / num_processors
    for n in range(numsims):
        blue_picks = 0
        for i in range(num_games):
            pick = random.randint(0,i+1)
            if pick == 0:
                blue_picks += 1
        if blue_picks > num_games / 2:
            blues += 1
    return blues


if __name__ == '__main__':
    pool = Pool()
    result = pool.map(worker, range(num_processors))
    print result
    result = sum(result)
    print 1 / (result / float(num_simulations))



#print fractions.Fraction(num_wins, num_simulations), float(fractions.Fraction(num_wins,num_simulations)), 1 / float(fractions.Fraction(num_wins, num_simulations))
#print fractions.Fraction(11,120), float(fractions.Fraction(11, 120)), 1 / float(fractions.Fraction(11,120))
