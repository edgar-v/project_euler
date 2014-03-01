#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

/*
This was solved by guessing that the number of spaces would be one of the most used characters in the text. by a bit of guesswork it was concluded that the 3rd key digit had to be 100. from there it is only about 30 solutions who match the rest of the criteria so it was easy to solve
*/

using namespace std;

int main()
{
    ifstream fin("problem59.txt");
    vector<int> values;
    string line;
    getline(fin, line);
    int start = 0;
    map<int, int> occurence;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            int number = atoi(line.substr(start, i - start).c_str());
            values.push_back(number);
            occurence[number]++;
            start = i + 1;
        }
    }
    /*
    for (map<int, int>::iterator it = occurence.begin(); it != occurence.end(); it++)
    {
        cout << (*it).first << ": " << (*it).second << endl;
    }
    */
    values.push_back(atoi(line.substr(start, 2).c_str()));
    for (int i = 103; i < 104; i++)
    {
        for (int j = 111; j < 112; j++)
        {
            for (int l = 100; l < 101; l++)
            {
                int key[] = {i, j, l};
                string output = "";
                bool isGood = true;
                int sum = 0;
                for (int k = 0; k < values.size(); k++)
                {
                    char newVal = values[k] ^ key[k % 3];
                    sum += newVal;
                    if (newVal < 32 || newVal > 126)
                    {
                        isGood = false;
                        break;
                    }
                    output += newVal;
                }
                if (isGood)
                {
                    cout << sum << endl;
                }
            }
        }
    }
    return 0;
}
