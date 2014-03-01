#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    long long int total = 0;

    for (long long int i = 1000000000; i < 10000000000; i++)
    {
        if ((i % 1000) % 17 != 0)
        {
            continue;
        }
        if (((i % 10000) / 10) % 13 != 0)
        {
            continue;
        }
        if (((i % 100000) / 100) % 11 != 0)
        {
            continue;
        }
        if (((i % 1000000) / 1000) % 7 != 0)
        {
            continue;
        }
        if (((i % 10000000) / 10000) % 5 != 0)
        {
            continue;
        }
        if (((i % 100000000) / 100000) % 3 != 0)
        {
            continue;
        }
        if (((i % 1000000000) / 1000000) % 2 != 0)
        {
            continue;
        }
        vector<bool> digits(10, false);
        long long int number = i;
        bool isGood = true;
        while (number >= 10)
        {
            int newDigit = number % 10;
            if (digits[newDigit] == false)
            {
                digits[newDigit] = true;
            }
            else
            {
                isGood = false;
                break;
            }
            number /= 10;
        }
        if (isGood)
            isGood = digits[number] ? false : true;
        
        if (isGood)
        {
            cout << i << endl;
            total += i;
        }

    }
    cout << total << endl;
    return 0;
}
