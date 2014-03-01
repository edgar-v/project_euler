#include <iostream>
#include <vector>

using namespace std;

int getSum(int n)
{
    int sum = 0;
    int uBound = (int) (n / 2) + 1;
    for (int i = 1; i < uBound; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int total = 0;

    for (int i = 220; i < 10000; i++)
    {
        int a = getSum(i);
        int b = getSum(a);
        
        if (b == i && b != a)
        {
            total += b;
            cout << i << " " <<  b << endl;
        }
    }

    cout << "total: " <<  total << endl;
    return 0;
}
