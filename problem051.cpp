#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

// Sieve of Eratosthenes
vector<int> sieve(int upperBound)
{
    int sqrtUpperBound = sqrt(upperBound);
    vector<int> primes(upperBound, true);
    for (int i = 2; i < sqrtUpperBound; i++)
    {
        if (primes[i])
        {
            for (int j = pow(i, 2); j < upperBound; j += i)
            {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    int roof = 10000000;
    vector<int> primes = sieve(roof);
    int currentNumber = 10;
    for (int i = 1; i <= currentNumber / 10; i++) // How many numbers we are replacing
    {
        for (int j = 
    }


}

