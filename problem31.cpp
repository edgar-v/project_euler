#include <iostream>
#include <vector>

using namespace std;

int total = 0;

void sumUpRec(int coins[], int target, vector<int> partial)
{
    int s = 0;
    for (int i = 0; i < partial.size(); i++)
    {
        s += partial[i];
    }
    if (s == target)
    {
        total++;
    }
    else if (s > target)
    {
        return;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (partial.size() == 0)
            {
                vector<int> np;
                np.push_back(coins[i]);
                sumUpRec(coins, target, np);
                continue;
            }
            if (coins[i] >= partial[partial.size() - 1])
            {
                vector<int> newPartial = partial;
                newPartial.push_back(coins[i]);
                sumUpRec(coins, target, newPartial);
            }
        }
    }
}

void sumUp(int coins[], int target)
{
    vector<int> partial;
    sumUpRec(coins, target, partial);
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int totalSum = 200;
    sumUp(coins, totalSum);
    cout << total << endl;
    return 0;
}
