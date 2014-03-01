#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

string toStr(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

int toInt(char ch)
{
    stringstream ss;
    ss << ch;
    int r;
    ss >> r;
    return r;
}

int main()
{
    int number = 2;
    int total = 0;
    int max = pow(9, 5) * 5;
    while (number < max)
    {
        int sum = 0;
        string num = toStr(number);
        for (int i = 0; i < num.size(); i++)
        {
            int n = toInt(num[i]);
            sum += pow(n, 5);
        }
        if (sum == number)
        {
            total += number;
        }
        number++;
    }

    cout << total << endl;
}
