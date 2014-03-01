#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

string toStr(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

bool tenPalindrome(int number)
{
    string num = toStr(number);
    string rnum = string(num.rbegin(), num.rend());
    return num == rnum;
}

bool twoPalindrome(int number)
{
    int numb = number;
    vector<int> powers;
    string num = "";
    for (int i = 0; i <= 20; i++)
    {
        powers.push_back(pow(2, i));
    }
    for (int i = powers.size() - 1; i >= 0; i--)
    {
        if (numb >= powers[i])
        {
            num += "1";
            numb -= powers[i];
        }
        else if (num != "")
        {
            num += "0";
        }
    }
    if (num == "")
    {
        return false;
    }
    string rnum = string(num.rbegin(), num.rend());
    return num == rnum;
}

int main()
{
    int total = 0;
    for (int i = 1; i < 1000000; i++)
    {
        if (tenPalindrome(i) && twoPalindrome(i))
        {
            total += i;
        }
    }
    cout << total << endl;
}
