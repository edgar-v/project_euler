#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> sieveOfE(int n)
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

int main()
{   
    vector<bool> primes = sieveOfE(99999999);
    int highest = 0;
    for (int i = 100; i < primes.size(); i++)
    {
        if (!primes[i])
        {
            continue;
        }
        int val = i;
        int length = 1;
        while (val >= 10)
        {
            val /= 10;
            length++;
        }
        vector<bool> isUsed(length + 1, false);
        val = i;
        while (val >= 10)
        {
            isUsed[val % 10] = true;
            val /= 10;
        }
        isUsed[val] = true;
        bool isGood = true;
        for (int j = 1; j < isUsed.size(); j++)
        {
            if (!isUsed[j])
            {
                isGood = false;
                break;
            }
        }
        if (isGood)
        {
            highest = i;
        }
    }
    cout << highest << endl;
    return 0;
}   
