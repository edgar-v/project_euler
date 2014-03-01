#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> sieve(int n)
{
    vector<bool> primes;
    for (int i = 0; i < n; i++)
    {
        primes.push_back(true);
    }
    int sqrN = sqrt(n);
    for (int i = 2; i < sqrN; i++)
    {
        if (primes[i] == true)
        {
            for (int j = pow(i, 2); j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    vector<bool> primes = sieve(1000000);
    vector<int> primeNum;
    for (int i = 2; i< primes.size(); i++)
    {
        if (primes[i] == true)
        {
            primeNum.push_back(i);
        }
    }
    int bestCount = 0;
    int bestTot = 0;
    for (int i = 0; i < primeNum.size(); i++)
    {   
        int count = 0;
        int total = 0;
        for (int j = i; j < primeNum.size(); j++)
        {
            total += primeNum[j];
            if (total > 1000000)
            {
                break;
                
            }
            count++;
            if (primes[total] == true)
            {
                if (count > bestCount)
                {
                    bestCount = count;
                    bestTot = total;
                }
            }
        }
    }
    cout << bestTot << endl;
}
