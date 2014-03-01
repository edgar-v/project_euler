#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


int main()
{
    map<long long, long long> occurance;
    
    int count = 1;
    while (true)
    {
       long long newcube = pow(count, 3);
       long long orgcube = newcube;
       string num = static_cast<ostringstream*>( &(ostringstream() << newcube) )->str();
       vector<int> digits;
       for (int i = num.size(); i > 1; i--)
       {
           digits.push_back(newcube / pow(10, i - 1));
           newcube = newcube % long(pow(10, i - 1));
       }
       digits.push_back(newcube);
       sort (digits.begin(), digits.end());
       long long key = 0;
       for (int i = 0; i < digits.size(); i++)
       {
            key += digits[i] * pow(10, i);
       }
       if (key == 987655433210)
           cout << orgcube << " " << key << endl;
       if (occurance[key] == 0)
           occurance[key] = 1;
       else if (occurance[key] == 4)
       {
           cout << key << endl;
           break;
       }
       else 
       {
           occurance[key]++;
       }
       count++;
    }
    return 0;
}
