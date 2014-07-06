#include <iostream>
#include <vector>
#include <set>
#include <cmath>

std::vector<int> sieveOfE(int n)
{
    std::vector<bool> primes;

    for(int i = 0; i < n; i++)
        primes.push_back(true);

    int squareN = std::sqrt(n);
    for(int i = 2; i < squareN; i++)
    {
        if (primes[i] == true)
        {
            for (int j = std::pow(i, 2); j < n; j+= i)
            {
                primes[j] = false;
            }
        }
    }
    std::vector<int> primesList;
    for (int i = 2; i < primes.size(); i++)
    {
        if (primes[i] == true)
        {
            primesList.push_back(i);
        }
    }
    return primesList;
}

int main()
{
    int n = 10000000;
    std::vector<int> primes = sieveOfE(n);
    for (int i = 1; i < n; i++)
    {
        std::set<int> factors;
        factors.insert(1);
        int num = i;
        int counter = 0;
        while (num != 1)
        {
            if (num % primes[counter] == 0)
            {
                factors.insert(primes[counter]);
                num /= primes[counter];
            }
            else
            {
                counter++;
            }
        }
        std::vector<bool> relPrimes;
        for (int j = 0; j < i + 1; j++)
        {
            relPrimes.push_back(true);
        }
        relPrimes[i] = false;
        for (std::set<int>::iterator it = factors.begin(); it != factors.end(); ++it)
        {
            if (*it == 1)
                continue;
            for (int j = 1; j < i + 1; j++)
            {
                if ((*it) * j >= relPrimes.size())
                    break;
                relPrimes[(*it) * j] = false;
            }
        }
        int sum = 0;
        for (int j = 1; j < relPrimes.size(); j++)
            if (relPrimes[j] == true)
            {
                sum++;
            }
        std::cout << "sum: " << sum << std::endl;
    }
}
