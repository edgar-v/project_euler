#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int indexOfSmallestElement(int nums[], int size)
{
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (nums[i] < nums[index])
            index = i;
    }

    return index;
}

int sum(vector<int> v)
{
    int ret = 0;
    for (std::vector<int>::iterator j = v.begin(); j != v.end(); ++j)
        ret += *j;

    return ret;
}

int main()
{
    vector<long> solutions;
    int nums[10] = {3, 2, 4, 1, 6, 5, 10, 7, 9, 8};

    int s1, s2, s3, s4, s5;

    do {
        vector<vector<int> > lines;
        vector<int> line1 = { nums[0], nums[1], nums[2] };
        vector<int> line2 = { nums[3], nums[2], nums[4] };
        vector<int> line3 = { nums[5], nums[4], nums[6] };
        vector<int> line4 = { nums[7], nums[6], nums[8] };
        vector<int> line5 = { nums[9], nums[8], nums[1] };

        s1 = sum(line1);
        s2 = sum(line2);
        s3 = sum(line3);
        s4 = sum(line4);
        s5 = sum(line5);
       
        if (s1 == s2 && s1 == s3 && s1 == s4 && s1 == s5)
        {
            // Solution found

            lines.push_back(line1);
            lines.push_back(line2);
            lines.push_back(line3);
            lines.push_back(line4);
            lines.push_back(line5);

            int externalNodes[] = { nums[0], nums[3], nums[5], nums[7], nums[9] };
            
            int index = indexOfSmallestElement(externalNodes, sizeof(externalNodes) / sizeof(int));
                
            std::rotate(lines.begin(), lines.begin() + index, lines.end());
            
            string solution = "";


            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    solution += std::to_string(lines[i][j]);
                }
            }

            if (solution.length() == 16)
                solutions.push_back(atol(solution.c_str()));
        }

    } while (std::next_permutation(nums, nums+10));
    

    cout << *std::max_element(solutions.begin(), solutions.end()) << endl;
}
