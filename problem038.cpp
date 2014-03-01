#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int getLength(int i)
{
    stringstream ss;
    ss << i;
    string lString = ss.str();
    return lString.size();
}

string toString(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int main()
{
    long long int  bNumber = 0;
    for (int i = 1; i < 100000; i++)
    {
        int length = 0;
        int index = 1;
        vector<int> numbers;
        while (length < 9)
        {
            numbers.push_back(i * index);
            length += getLength(i * index);
            index++;
        }
        if (length > 9)
            continue;
        vector<bool> digits(10, false);
        for (int j = 0; j < numbers.size(); j++)
        {
            int val = numbers[j];
            while (val >= 10)
            {
                digits[val % 10] = true;
                val /= 10;
            }
            digits[val] = true;
        }
        bool isGood = true;
        for (int j = 1; j < digits.size(); j++)
        {
            if (!digits[j])
            {
                isGood = false;
                break;
            }
        }
        if (isGood)
        {
            string number = "";
            for (int j = 0; j < numbers.size(); j++)
            {
                number += toString(numbers[j]);
            }
            long long int rNumber = atoi(number.c_str());
            if (rNumber > bNumber)
            {
                bNumber = rNumber;
            }
        }
    }
    cout << bNumber << endl;
}
