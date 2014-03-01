#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

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

int main()
{
    vector<bool> primes = sieve(100000);
    int a = 0;
    int b = 0;
    int bestCount = 0;
    for (int i = -999; i < 1000; i++)
    {
        for (int j = -999; j < 1000; j++)
        {
            int n = 0;
            int count = 0;
            int index = pow(n, 2) + (i * n) + j;
            if (index < 0)
            {
                if (count > bestCount)
                {
                    bestCount = count;
                    a = i;
                    b = j;
                }
                continue;
            }
            while (primes[index])
            {
                count++;
                n++;
                index = pow(n, 2) + (i * n) + j;
                if (index < 0)
                    break;
            }
            if (count > bestCount)
            {
                bestCount = count;
                a = i;
                b = j;
            }

        }
    }
    cout << a * b << endl;
    return 0;
}
