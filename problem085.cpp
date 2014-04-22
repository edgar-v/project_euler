#include <vector>
#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int dx = 5;
    int dy = 5;
    int total = 0;
    int prevDimensions;
    int prevTotal = 0;

    while (true)
    {
        total = 0;
        for (int i = 1; i <= dx; i++)
        {
            for (int j = 1; j <= dy; j++)
            {
                int squares = (dx - i + 1) * (dy - j + 1);
                total += squares;
            }
            if (total > 2000000)
                break;
        }
        if (std::abs(2000000 - prevTotal) > std::abs(2000000 - total))
        {
            prevDimensions = dx * dy;
            prevTotal = total;
        }
        if (dy == 100)
            break;
        if (dx == 100)
            dy++,dx=0;
        dx++;
    }

    std::cout << prevDimensions << std::endl;

    return 0;
}
