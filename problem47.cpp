#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> sieveOfE(int n)
{
    int squareN = sqrt(n);
    vector<int> primes(n, true);
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
    int roof = 1000000;
    vector<int> primes = sieveOfE(roof);
    vector<int> primeNums;
    for (int i = 2; i < primes.size(); i++)
    {
        if (primes[i])
        {
            primeNums.push_back(i);
        }
    }
    for (int i = 644; i < roof; i++)
    {
        bool isGood = true;
        vector<int> factors(i + 4, false);
        for (int j = i; j < (i + 4); j++)
        {
            if (primes[j])
            {
                isGood = false;
                break;
            }
            int num = j;
            vector<int> newFactors;
            while (num >= 2)
            {
                for (int i = 0; i < primeNums.size(); i++)
                {
                    if (num % primeNums[i] == 0)
                    {
                        newFactors.push_back(primeNums[i]);
                        num /= primeNums[i];
                        break;
                    }
                }
            }
            vector<int> actfacts;
            for (int k = 0; k < newFactors.size(); k++)
            {
                int actFact = newFactors[k];
                int duplicates = 1;
                while (newFactors.size() > k + 1 && actFact == newFactors[k+duplicates])
                {
                    duplicates++;
                }

                actFact = pow(actFact, duplicates);
                k += duplicates - 1;
                actfacts.push_back(actFact);
            }
            if (actfacts.size() != 4)
            {
                isGood = false;
                break;
            }
            for (int k = 0; k < actfacts.size(); k++)
            {
                int actFact = actfacts[k];
                if (factors[actFact] == false)
                {
                    factors[actFact] = true;
                }
                else
                {
                    isGood = false;
                    break;
                }
            }
        }
        if (isGood)
        {
            cout << i << endl;
            return 0;
        }
    }
}
