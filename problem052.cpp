#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > getDigits(vector<int> numbers)
{
    vector<vector<int> > digits;
    for (int i = 0; i < numbers.size(); i++)
    {
        vector<int> vi;
        int num = numbers[i];
        while (num > 10)
        {
            vi.push_back(num % 10);
            num /= 10;
        }
        vi.push_back(num);
        digits.push_back(vi);
    }
    return digits;
}

int main()
{
    int number = 100;
    while (true)
    {
        vector<int> numbers;
        for (int i = 1; i < 7; i++)
        {
            numbers.push_back(number * i);
        }
        vector<vector<int> > digits = getDigits(numbers);
        int length = digits[0].size();
        bool tooLong = false;
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i].size() != length)
            {
                tooLong = true;
                break;
            }
        }
        if (tooLong)
        {
            number++;
            continue;
        }
        for (int i = 0; i < digits.size(); i++)
        {
            sort(digits[i].begin(), digits[i].end());
        }
        bool isGood = true;

        for (int i = 0; i < length; i++)
        {
            int base = digits[0][i];
            for (int j = 1; j < digits.size(); j++)
            {
                if (digits[j][i] != base)
                {
                    isGood = false;
                    break;
                }
            }
            if (!isGood)
            {
                break;
            }
        }
        if (isGood)
        {
            cout << number << endl;
            break;
        }
        number++;
    }
    return 0;
}
