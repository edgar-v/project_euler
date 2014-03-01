#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("problem42.txt");
    string text;
    fin >> text;
    vector<string> words;
    int a = 1;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ',')
        {
            words.push_back(text.substr(a, i - a - 1));
            a = i + 2;
        }
    }
    words.push_back(text.substr(a, text.size() - a - 1));
    
    vector<int> triNum;
    for (int i = 0; i < 20; i++)
    {
        triNum.push_back(((i * i) + i) / 2);
    }

    int total = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            sum += (words[i][j] - 64);
        }
        for (int j = 0; j < triNum.size(); j++)
        {
            if (sum == triNum[j])
            {
                total++;
            }
        }
    }
    cout << total << endl;

    return 0;
}
