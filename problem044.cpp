#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int min = 1000000000;    
    vector<bool> pents(10000000000, false);
    vector<long long int> pentNums;
    for (int i = 1; i < 20000; i++)
    {
        long long int num = i * (3 * i - 1) / 2;
        pentNums.push_back(num);
        pents[num] = true;
        cout << num << endl;
    }
    for (int i = 0; i < pentNums.size(); i++)
    {
        for (int j = i + 1; j < pentNums.size(); j++)
        {
            if (pents[pentNums[i] + pentNums[j]] == true && pents[pentNums[j] - pentNums[i]] == true)
            {
                if ((pentNums[j] - pentNums[i]) < min)
                {
                    cout << pentNums[j] << " " << pentNums[i] << endl;
                    min = pentNums[j] - pentNums[i];
                    cout << min << endl;
                }
            }
        }
    }
}
