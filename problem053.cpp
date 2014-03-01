#include <iostream>
#include <vector>

using namespace std;

long long int factorial(int num)
{
    long long int sum = 1;
    for (int i = num; i > 0; i--)
    {
        sum *= i;
    }
    return sum;
}

int main()
{
    int total = 0;
    for (int n = 1; n < 101; n++)
    {
        for (int r = 1; r <= n; r++)
        {
            long long int nFac = factorial(n);
            long long int rFac = factorial(r) * factorial(n - r);
            
            long long int total = nFac / rFac;
            cout << nFac << " " << rFac << " " << total << endl;
            if (total > 1000000)
            {
                total += 1;
            } 
        }
    }
    cout << total << endl;
}
