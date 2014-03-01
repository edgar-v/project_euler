#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> getDigits(int n)
{
    vector<int> digits;
    while (n >= 10)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    digits.push_back(n);
    return digits;
}

int main()
{
    int totalI = 1, totalJ = 1;    
    for (int i = 10; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            double fraction = (double) i / (double)j;
            double iVal = i;
            double jVal = j;
            vector<int> digitsInI = getDigits(i);
            vector<int> digitsInJ = getDigits(j);
            int iOne = digitsInI[0], iTwo = digitsInI[1];
            int jOne = digitsInJ[0], jTwo = digitsInJ[1];
            double newFraction = 0;
            if (iOne == 0 && jOne == 0)
            {
                continue;
            }
            if (iOne == jOne)
            {
                newFraction = (double)(iTwo) / (double)(jTwo);
            }
            else if (iOne == jTwo)
            {       
                newFraction = (double)(iTwo) / (double)(jOne);
            }   
            else if (iTwo == jOne)
            {
                newFraction = (double)(iOne) / (double)(jTwo);
            }
            else if (iTwo == jTwo)
            {
                newFraction = (double)(iOne) / (double)(jOne);
            }
            if (newFraction == fraction)
            {
                
                int counter = 100;
                while (true)
                {
                    if (i % counter == 0 && j % counter == 0)
                    {
                        break;
                    }
                    counter--;
                }
                totalI *= i / counter;
                totalJ *= j / counter;
            }
        }
    }
    cout << totalJ / totalI << endl;
}
