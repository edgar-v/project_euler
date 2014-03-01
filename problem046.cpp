#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> sieve(int n)
{
    vector<int> primes(n, true);
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
    int index = 9;
    vector<int> primes = sieve(100000);
    while (index < 100000)
    {
        int impossible = true;
        for (int i = 2; i < index; i++)
        {
            int val = 0;
            if (primes[i])
            {
                val += i;
                int exp = 1;
                while (true)
                {
                    val += 2 * pow(exp, 2);
                    if (val == index)
                    {
                        impossible = false;
                        break;
                    }
                    if (val > index)
                        break;
                    val -= 2 * pow(exp, 2);
                    exp++;
                }
            }
        }
        if (impossible == true)
        {
            cout << index << endl;
            break;
        }
        index++;
        while (primes[index] == true || index % 2 == 0)
            index++;
    }
}
