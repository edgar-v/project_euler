#!/usr/bin/python

from sys import stdin

def flush(cards):
    if cards[0][1] == cards[1][1] == cards[2][1] == cards[3][1] == cards[4][1]:
        return True
    return False


def rflush(cards):
    if flush(cards):
        face = [cards[0][0], cards[1][0], cards[2][0], cards[3][0], cards[4][0]]
        face.sort()
        if face == ['A', 'K', 'K', 'Q', 'T']:
            return True
    return False

def sflush(cards):
    if flush(cards) and straight(cards):
        return True
    return False


print(rflush([['T','H'],['K','H'],['Q','H'],['K','H'],['A','H']]))
