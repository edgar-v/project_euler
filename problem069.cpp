#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int findRelativePrimeNums(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            result -= result / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) result -= result / n;
   
    return result;
}

int main()
{
    double bestValue = 0;
    int bestN = 1; 
    for (int i = 2; i < 1000001; i++)
    {
        int relativePrimeNums = findRelativePrimeNums(i);
        if ((double) i / (double)relativePrimeNums > bestValue)
        {
            bestValue = (double) i / (double)relativePrimeNums;
            bestN = i;
        }
    }
    cout << bestN << endl;
    return 0;
}
