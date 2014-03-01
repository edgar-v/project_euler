#include <iostream>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// See python solution

int main()
{
    int total = 0;
    vector<long long int> numbers;
    vector<int> power;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 22; j++)
        {
            numbers.push_back(pow(i, j));
            power.push_back(j);
        }
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        int size = 1;
        long long int val = numbers[i];
        while (val >= 10)
        {
            size++;
            val /= 10;
        }
        if (size == power[i])
        {
            cout << numbers[i] << endl;
            total++;
        }
    }
    cout << total << endl;
    return 0;
}
