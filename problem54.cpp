#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Card {
    int val;
    char suit;
};

int getHandValue(vector<Card> hand)
{
    vector<int> values;
    for (int i = 0; i < hand.size(); i++)
    {
        values.push_back(hand[i].val);
    }
    sort(values.begin(), values.end());
}

int checkHands(vector<Card> player1, vector<Card> player2)
{
    int handType1 = getHandValue(player1);
    int handType2 = getHandValue(player2);
    
}

int main()
{
    ifstream fin("problem54.txt");
    string newLine;
    int total = 0;
    while (getline(fin, newLine))
    {
        vector<Card> player1;
        for (int i = 0; i < 13; i++)
        {
            Card newCard;
            newCard.val = atoi(newLine.substr(i, 1).c_str());
            newCard.suit = newLine[i+1];
            player1.push_back(newCard);
            i += 2;
        }
        vector<Card> player2;
        for (int i = 12; i < 25; i++)
        {
            Card newCard;
            newCard.val = atoi(newLine.substr(i, 1).c_str());
            newCard.suit = newLine[i+1];
            player2.push_back(newCard);
            i+= 2;
        }
        total += checkHands(player1, player2);
    }
    cout << total << endl;
    return 0;
}
