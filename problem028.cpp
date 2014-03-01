#include <iostream>

using namespace std;

int main()
{
    int currentNumber = 1;
    int total = 0;
    for (int i = 1; i <= 1001; i += 2)
    {
        int nInSpiral = i * i;
        if (nInSpiral == 1)
        {
            currentNumber++;
            total++;
            continue;
        }

        int br = currentNumber + ( i - 2);
        int lr = br + (i - 1);
        int tl = lr + (i - 1);
        int tr = tl + (i - 1);
        total += br + lr + tl + tr;
        currentNumber = tr + 1;

    }

    cout << total << endl;

    return 0;
}
