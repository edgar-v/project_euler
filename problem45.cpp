#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int t = 286, p = 165, h = 143;
    while (true)
    {
        long long int newT = (t * (t + 1)) / 2;
        long long int newP = (p * (3 * p - 1)) / 2;
        long long int newH = (h * (4 * h - 2)) / 2;
        while (newP < newT)
        {
            p++;
            newP = (p * (3 * p - 1)) / 2;
        }
        while (newH < newT)
        {
            h++;
            newH = (h * (4 * h - 2)) / 2;
        }
        if (newT == newP && newT == newH)
        {
            cout << newT << endl;
            return 0;
        }
        t++;
    }
    return 0;
}

