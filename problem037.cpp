#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

string toStr(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

vector<bool> sieve(int n)
{
    vector<bool> primes(n, true);
    int squareN = sqrt(n);
    for (int i = 2; i < squareN; i++)
    {
        if (primes[i])
        {
            for (int j = pow(i, 2); j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

vector<int> getRightNums(int i)
{
    vector<int> nums;
    string number = toStr(i);
    for (int i = 0; i < number.size(); i++)
    {
        string partNum = number.substr(0, i + 1);
        nums.push_back(atoi(partNum.c_str()));
    }
    return nums;
}

vector<int> getLeftNums(int i)
{
    vector<int> nums;
    string number = toStr(i);
    for (int i = 0; i < number.size(); i++)
    {
        string partNum = number.substr(i, number.size() - 1);
        nums.push_back(atoi(partNum.c_str()));
    }
    return nums;
}

int main()
{
    vector<bool> primes = sieve(1000000);
    primes[0] = false;
    primes[1] = false;
    int total = 0;
    for (int i = 10; i < primes.size(); i++)
    {
        if (primes[i])
        {
            vector<int> leftSideNums = getLeftNums(i);
            vector<int> rightSideNums = getRightNums(i);
            bool truncPrime = true;
            for (int j = 0; j < leftSideNums.size(); j++)
            {
                if (!primes[leftSideNums[j]] || !primes[rightSideNums[j]])
                {
                    truncPrime = false;
                }
            }
            if (truncPrime)
            {
                total += i;
                cout << i << endl;
            }
        }
    }
    cout << total << endl;
    return 0;
}

