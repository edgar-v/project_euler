#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    std::string iString = "1020304050607080900";
    long long int i = std::sqrt(std::stoi(iString));
    while (true)
    {
        long long int iSquared = i * i;
        if (iSquared % 10 != 0)
        {
            i++;
            continue;
        }
        std::string iText = std::to_string(iSquared);
        if (iText.size() < 19)
        {
            i++;
            continue;
        }
        std::cout << iSquared << std::endl;
        bool good = true;
        for (int j = 0; j < 9; j++)
        {
            std::string jString = std::to_string(j+1);
            if (iText[j*2] != jString[0])
            {
                int num = std::stoi(iText[j*2]);
                if (j == 1 && num > 2)
                {
                    i = std::sqrt(
                }
                good = false;
                i++;
                break;
            }
        }
        if (good == true)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
}
