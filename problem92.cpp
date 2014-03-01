#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

string toStr(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

vector<int> examine(int n)
{
    int currentNumber = n;
    string number = toStr(currentNumber);
    vector<int> numbers;
    while (currentNumber != 1 && currentNumber != 89)
    {
        numbers.push_back(currentNumber);
        int nextNum = 0;
        for (int i = 0; i < number.size(); i++)
        {
            string str = "";
            str += number[i];
            nextNum += pow(atoi(str.c_str()), 2);
        }
        currentNumber = nextNum;
        number = toStr(currentNumber);
    }
    numbers.push_back(currentNumber);
    return numbers;
}

int main()
{  
    set<int> arrivesAt89;
    int total = 0;
    for (int i = 2; i < 10000000; i++)
    {
        if (arrivesAt89.count(i) == 0)
        {
            vector<int> numbers = examine(i);
            if (numbers[numbers.size() - 1] == 89)
            {
                for (int j = 0; j < numbers.size(); j++)
                {
                    arrivesAt89.insert(numbers[j]);
                }
                total += 1;
            }
        }
        else
        {
            total++;
        }
        if ( i % 100000 == 0)
        {
            cout << i / 100000 << "%" <<  endl;
        }
    }
    cout << total << endl;
    return 0;
}
