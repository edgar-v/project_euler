#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<bool> generatePrimes(int n)
{
    vector<bool> isPrime;
    for (int i = 0; i < n; i++)
    {
        isPrime.push_back(true);
    }
    int squaren = sqrt(n);
    for (int i = 2; i < squaren; i++)
    {
        if (isPrime[i] == true)
        {
            int count = 0;
            for (int j = pow(i,2); j < n; j += i)
            {
                isPrime[j] = false;
                count++;
            }
        }
    }
    return isPrime;
}

vector<int> getCircularNumbers(int i)
{
    vector<int> digits;
    while (i >= 10)
    {
        digits.push_back(i % 10);
        i /= 10;
    }
    digits.push_back(i);
    vector<int> numbers;
    for (int i = 0; i < digits.size(); i++)
    {
        int number = 0;
        for (int j = 0; j < digits.size(); j++)
        {
            number += digits[(j+i) % digits.size()] * pow(10, j);
        }
        numbers.push_back(number);
    }
    return numbers;
}

int main()
{
    int total = 0;
    int roof = 1000000;
    vector<bool> primes = generatePrimes(roof);
    for (int i = 2; i < roof + 1; i++)
    {
        vector<int> numbers = getCircularNumbers(i);
        bool circularPrime = true;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (primes[numbers[j]] == false)
            {
                circularPrime = false;
                break;
            }
        }
        if (circularPrime == true)
        {
            total++;
        }
    }
    cout << total << endl;
    return 0;
}
