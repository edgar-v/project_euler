#include <iostream>
#include <math.h>

int main()
{
    unsigned long long int sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
        long long int a = i;
        for (int j = 1; j < i; j++)
        {
            a = (a * i) % 10000000000;
        }
        sum = (sum + a) % 10000000000;
        std::cout << a << std::endl;
    }

    std::cout << sum << std::endl;

    return 0;
}
