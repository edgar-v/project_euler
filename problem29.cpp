#include <set>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

string toStr(int a)
{
    stringstream ss;
    ss << a;
    return ss.str();
}

string getValue(int a, int b)
{
    vector<int> factors;
    int fa = a;
    string toreturn = "";
    for (int i = 2; i <= fa; i++)
    {
        if (fa % i == 0)
        {
            factors.push_back(i);
            fa /= i;
            i--;
        }
    }
    for (int i = 0; i < factors.size(); i++)
    {
        string num = toStr(factors[i]);
        for (int j = 0; j < b; j++)
        {
            toreturn += num;
        }
    }
    return toreturn;
}

int main()
{
    set<string> values;
    int total = 0;

    for (int i = 2; i <= 100; i++)
    {
        for (int j = 2; j <= 100; j++)
        {
            string value = getValue(i, j);
            values.insert(value);
        }
    }
    set<string>::iterator it;
    for (it = values.begin(); it != values.end(); it++)
    {
        total++;
    }
    cout << total << endl;
}
