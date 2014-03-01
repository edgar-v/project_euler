#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("problem82.txt");
    vector<string> lines;
    while (fin.good())
    {
        string newLine;
        getline(fin, newLine);
        lines.push_back(newLine);
    }
    cout << lines[0] << endl;

    return 0;
}
