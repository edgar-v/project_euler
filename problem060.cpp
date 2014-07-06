#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

vector<bool> sieve(int n)
{
    vector<bool> primes;
    for (int i = 0; i < n; i++)
    {
        primes.push_back(true);
    }
    int squareN = sqrt(n);
    for (int i = 2; i < squareN; i++)
    {
        if (primes[i] == true)
        {
            for (int j = pow(i, 2); j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int concatInts(int a, int b)
{
    ostringstream oss;
    oss << a << b;
    istringstream iss(oss.str());
    int c;
    iss >> c;
    return c;
}

vector<int> generatePairs(int primes[])
{
    vector<int> nums;
    int primeslength = sizeof(primes) / sizeof(int);
    for (int i = 0; i < primeslength; i++)
    {
        for (int j = i + 1; j < primeslength; j++)
        {
            nums.push_back(concatInts(primes[i], primes[j]));
            nums.push_back(concatInts(primes[j], primes[i]));
        }
    }
    return nums;
}

int main()
{
    vector<bool> primes = sieve(100000000);
    int maxval = 10000;
    for (int i = 2; i < maxval; i++)
    {
        if (!primes[i])
            continue;
        cout << i << endl;
        for (int j = i + 1; j < maxval; i++)
        {
            if(!primes[j])
                continue;
            for (int k = j + 1; k < maxval; k++)
            {
                if (!primes[k])
                    continue;
                for (int l = k + 1; l < maxval; l++)
                {
                    if (!primes[l])
                        continue;
                    for (int m = l + 1; m < maxval; m++)
                    {
                        if (!primes[m])
                            continue;
                        int base[] = {i, j, k, l, m};
                        vector<int> concats = generatePairs(base);
                        bool allPrime = true;
                        for (int n = 0; n < concats.size(); n++)
                        {
                            if (primes[concats[n]] == false)
                                allPrime = false;
                        }
                        if (allPrime)
                            cout << i + j + k + l + m << endl;
                    }
                }
            }
        }
    }
}
