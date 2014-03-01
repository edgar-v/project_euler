#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("problem22.txt");
    vector<string> names;

    string namestring = "";
    getline(fin, namestring);
    
    fin.close();

    int a = 1;
    int b = 0;
    for (int i = 1; i < namestring.size(); i++)
    {
        if (namestring[i] == ',')
        {
            string newName = namestring.substr(a, (i - a - 1));
            names.push_back(newName);
            a = i + 2;
        }
    }
    names.push_back(namestring.substr(a, 6));

    sort(names.begin(), names.end());

    long long total = 0;
    for (int i = 0; i < names.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < names[i].size(); j++)
        {
            if (i == 0) cout << names[i][j] - 64 << " " << names[i][j] << endl;
            temp += names[i][j] - 64;
        }
        total += temp * (i+1);
        if (i == 0) cout << temp << endl;
    }

    cout << total << endl;
    return 0;
}
