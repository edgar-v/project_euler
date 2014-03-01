#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string toStr(long long int a)
{
    stringstream ss;
    ss << a;
    return ss.str();
}

int main()
{
    long long int i = 318000000;
    while (true)
    {
        long long int is = i * i;
        if (i % 100000 == 0)
        {
            cout << is << endl;
        }
        string text = toStr(is);
        if (text.size() < 18)
        {
            i++;
            continue;
        }
        bool good = true;
        for (int j = 0; j < 9; j++)
        {
            if (text[j*2] != toStr(j+1)[0])
            {
                good = false;
                i++;
                break;
            }
        }
        if (good == true && text[18] == '0')
        {
            cout << i << endl;
            return 0;
        }
    }
}
