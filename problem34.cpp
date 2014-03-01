#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string toStr(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int getNum(char s)
{
    stringstream ss;
    ss << s;
    int a;
    ss >> a;
    return a;
}

vector<int> getDigits(int n)
{
    vector<int> digits;
    string number = toStr(n);
    for (int i = 0; i < number.size(); i++)
    {
        digits.push_back(getNum(number[i]));
    }
    return digits;
}

int digitFactorialSum(int n)
{
    int sum = 0;
    vector<int> numbers = getDigits(n);
    for (int i = 0; i < numbers.size(); i++)
    {
        int factorialsum = 1;
        for (int j = numbers[i]; j > 1; j--)
        {
            factorialsum *= j;
        }
        sum += factorialsum;
    }
    return sum;
}

int main()
{
    int total = 0;
    for (int i = 3; i < 100000; i++)
    {
        if (i == digitFactorialSum(i))
        {
            total += i;
            cout << i << endl;
        }
    }
    cout << total << endl;
}
