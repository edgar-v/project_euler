#!/usr/bin/env python


def hand_value(hand):

    # I had some fun with one-liners :-)

    nums = [int(hand[i][:-1]) for i in range(0, len(hand))]

    handVal = 0
    extra_comparisons = sorted(nums,reverse=True)

    if all(hand[v][-1] == hand[0][-1] for v in range(0, len(hand))):
        handVal = max(5, handVal)    # Flush
        extra_comparisons = [max(nums)]

    if nums.count(1) == 1 and nums.count(10) == 1 and nums.count(11) == 1 and nums.count(12) == 1 and nums.count(13) == 1 and handVal == 5:
        handVal = 9 # Royal flush

    if all(x == y - 1 for x, y in zip(sorted([int(hand[i][:-1]) for i in range(0, len(hand))])[:-1], sorted([int(hand[i][:-1]) for i in range(0, len(hand))])[1:])):
        if handVal == 5:
            handVal = max(8, handVal)    # Straight flush
        else:
            handVal = max(4, handVal)    # Straight
        extra_comparisons = [max(nums)]
    numOfKind =  [[int(hand[i][:-1]) for i in range(0, len(hand))].count(int(hand[j][:-1])) for j in range(0, len(hand))]
    if max(numOfKind) == 4:
        handVal = max(7, handVal)    # Four of a kind
        extra_comparisons = [nums[numOfKind.index(max(numOfKind))-1], nums[numOfKind.index(min(numOfKind))-1]]
    elif numOfKind.count(2) == 2 and numOfKind.count(3) == 3:
        handVal = max(6, handVal)    # Full house
    elif max(numOfKind) == 3:
        handVal = max(3, handVal)    # Three of a kind
        extra_comparisons = [nums[numOfKind.index(max(numOfKind))]]
        extra_comparisons.extend(sorted([x for x in nums if x != extra_comparisons[0]], reverse=True))
    elif numOfKind.count(2) == 4:
        handVal = max(2, handVal)    # Two pairs
        extra_comparisons = sorted(list(set([x for x in nums if nums.count(x) == 2])), reverse=True)
        extra_comparisons.append(nums[numOfKind.index(min(numOfKind))])
    elif numOfKind.count(2) == 2:
        handVal = max(1, handVal)    # One Pair
        extra_comparisons = [nums[numOfKind.index(max(numOfKind))]]
        extra_comparisons.extend(sorted([x for x in nums if x != extra_comparisons[0]], reverse=True))

    return handVal, extra_comparisons

player1_wins = 0

f = open("hands.txt", "r")

linenum = -1
for line in f:
    linenum += 1
    cards = line.replace('\n', "").replace("A", "14").replace("T", "10").replace("J", "11").replace("Q", "12").replace("K", "13").split(" ")
    p1_hand = cards[:5]
    p2_hand = cards[5:]
    
    p1_val, p1_extra = hand_value(p1_hand)
    p2_val, p2_extra = hand_value(p2_hand)
    if p1_val > p2_val:
        player1_wins += 1
    elif p1_val == p2_val:
        for i in range(0, len(p1_extra)):
            if p1_extra[i] > p2_extra[i]:
                player1_wins += 1
                break
            elif p2_extra[i] > p1_extra[i]:
                break


print player1_wins
f.close()
