#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string toNumeral(int number)
{
    string numeral = "";
    while (number > 999)
    {
        numeral += "M";
        number -= 1000;
    }
    if (number > 899)
    {
        numeral += "CM";
        number -= 900;
    }
    if (number > 499)
    {
        numeral += "D";
        number -= 500;
    }
    if (number > 399)
    {
        numeral += "CD";
        number -= 400;
    }
    while (number > 99)
    {
        numeral += "C";
        number -= 100;
    }
    if (number > 89)
    {
        numeral += "XC";
        number -= 90;
    }
    if (number > 49)
    {
        numeral += "L";
        number -= 50;
    }
    if (number > 39)
    {
        numeral += "XL";
        number -= 40;
    }
    while (number > 9)
    {
        numeral += "X";
        number -= 10;
    }
    if (number > 8)
    {
        numeral += "IX";
        number -= 9;
    }
    if (number > 4)
    {
        numeral += "V";
        number -= 5;
    }
    if (number > 3)
    {
        numeral += "IV";
        number -= 4;
    }
    while (number > 0)
    {
        numeral += "I";
        number -= 1;
    }
    return numeral;
}

int getNumberFromNumeral(string line)
{
    char curChar = line[0];
    int count = 0;
    int total = 0;
    int values[] = {1, 5, 10, 50, 100, 500, 1000 };
    char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (int i = 0; i < line.size(); i++)
    {
        char thisChar = line[i];
        if (thisChar == curChar)
        {
            count++;
        }
        else
        {
            int cChar = 0;
            int tChar = 0;
            for (int j = 0; j < 7; j++)
            {
                if (curChar == numerals[j])
                {
                    cChar = j;
                }
                if (thisChar == numerals[j])
                {
                    tChar = j;
                }
            }
            if (cChar > tChar)
            {
                total += values[cChar] * count;
            }
            else
            {
                total -= values[cChar] * count;
            }
            curChar = thisChar;
            count = 1;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (curChar == numerals[i])
        {
            total += values[i] * count;
        }
    }
    return total;
}

int main()
{
    ifstream fin("problem89.txt");
    vector<string> numeral;
    while (fin.good())
    {
        string line;
        getline(fin, line);
        numeral.push_back(line);
    }


    int total = 0;
    for (int i = 0; i < numeral.size(); i++)
    {
        int number = getNumberFromNumeral(numeral[i]);
        string newNumeral = toNumeral(number);
        total += numeral[i].size() - newNumeral.size();
        cout << numeral[i] << " " << newNumeral << " : " << numeral[i].size() - newNumeral.size() <<  endl;
    }

    cout << total << endl;
    return 0;
}
