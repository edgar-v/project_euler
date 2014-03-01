#include <iostream>
#include <sstream>

using namespace std;

bool checkBouncy(int number)
{
    stringstream ss;
    ss << number;
    string num = ss.str();

    int change = 0;

    for (int i = 1; i < num.size(); i++)
    {
        switch (change)
        {
            case -1:
                if (num[i] > num[i-1])
                {
                    return true;
                }
                break;
            case 0:
                if (num[i] > num[i-1])
                {
                    change = 1;
                } 
                else if (num[i] < num[i-1])
                {
                    change = -1;
                }
                break;
            case 1:
                if (num[i] < num[i-1])
                {
                    return true;
                }
                break;
        }
    }
    return false;
}

int main()
{
    int bouncy = 1;
    int normal = 100;
    int i = 101;
    int percentage = (bouncy * 100) / (bouncy + normal);
    while (percentage < 99)
    {
        i++;
        if (checkBouncy(i) == true)
        {
            bouncy++;
        }
        else
        {
            normal++;
        }
        percentage = (bouncy * 100) / (bouncy + normal);
    }
    cout << i << endl;
}
