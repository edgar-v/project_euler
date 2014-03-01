#include <iostream>
#include <vector>

using namespace std;

bool isAbundant(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum > n;
}

bool isSumOfAbundantNums(int n, vector<int> numbers)
{
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (n == numbers[i] + numbers[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int total = 0;
    vector<int> abundantNums;
    for (int i = 1; i < 28123; i++)
    {
        if (isAbundant(i))
        {
            abundantNums.push_back(i);
        }
        if (!isSumOfAbundantNums(i, abundantNums))
        {
            total += i;
            cout << i << endl;
        } 
    }
    cout << total << endl;
}
