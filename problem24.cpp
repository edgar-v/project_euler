#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }

    for (int i = 1; i < 1000000; i++)
    {
        next_permutation(nums.begin(), nums.end());
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    cout << endl;

    return 0;
}
