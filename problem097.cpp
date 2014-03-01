#include <iostream>
#include <vector>

using namespace std;

int main()
{

    long long int number = 1;
    for (int i = 0; i < 7830457; i++)
    {
        number = (number * 2) % 10000000000;
    }
    cout << number * 28433 % 10000000000 << endl;

    return 0;
}
