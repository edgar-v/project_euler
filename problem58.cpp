#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> sieveOfE(long long int n)
{
    vector<bool> primes(n, true);
    int squareN = sqrt(n);
    for (int i = 2; i < squareN; i++)
    {
        if(primes[i])
        {
            for (long long int j = pow(i, 2); j < n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    vector<bool> primes = sieveOfE(700000000);
    long long int primeNumbers = 3;
    long long int nonPrimeNumbers = 5;
    int spiralSize = 3;
    long long int currentNumber = 9;
    while (((double)primeNumbers) / (double)(nonPrimeNumbers) > 0.1)
    {
        spiralSize += 2;
        for (int i = 0; i < 4; i++)
        {
            currentNumber += spiralSize - 1;
            if (primes[currentNumber])
                primeNumbers++;
            nonPrimeNumbers++;
        }
    }
    cout << spiralSize << endl;
    return 0;
}
