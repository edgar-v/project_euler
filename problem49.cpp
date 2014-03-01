#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<bool> primes = sieveOfE(10000);
    for (int i = 1000; i < 10000; i++)
    {
       if (!primes[i])
            continue;
       vector<int> iDigits;
       int iVal = i;
       for (int j = 0; j < 4; j++)
       {
            iDigits.push_back(iVal % 10);
            iVal /= 10;
       }
       sort(iDigits.begin(), iDigits.end());
       for (int j = 1; j < 4500; j++)
       {
            if (i + 2 * j > 100000)
               break;
            if (!primes[i+j] || !primes[i+2*j])
                continue;
            
            vector<int> jDigits1;
            vector<int> jDigits2;
            int val = i+j;
            int val2 = i + j * 2;
            for (int k = 0; k < 4; k++)
            {
                jDigits1.push_back(val % 10);
                jDigits2.push_back(val2 % 10);

                val2 /= 10;
                val /= 10;
            }
            sort(jDigits1.begin(), jDigits1.end());
            sort(jDigits2.begin(), jDigits2.end());
            bool isGood = true;
            for (int k = 0; k < 4; k++)
            {
                if (iDigits[k] != jDigits1[k] || iDigits[k] != jDigits2[k])
                {
                    isGood = false;
                    break;
                }
            }
            if (isGood)
            {
                cout << i << " " << i + j << " " << i + j*2 << endl;
            }
       }
    }
}
