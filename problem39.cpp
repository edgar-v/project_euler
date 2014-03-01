#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int bestP = 0;
    int best = 0;
    for (int p = 12; p < 1000; p++)
    {
        int solutions = 0;
        for (int i = 1; i < p - 2; i++)
        {
            for (int j = i; j < p - i - 1; j++)
            {
                int k = p - i - j;
                if (((pow(i, 2) + pow(j, 2)) == pow(k, 2)) && k != i && k != j)
                {
                    solutions++;
                }
            }   
        }
        if (solutions > best)
        {
            best = solutions;
            bestP = p;
        }
    }
    cout << bestP << endl;
    return 0;
}
