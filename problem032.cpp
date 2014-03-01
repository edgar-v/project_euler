#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int total = 0;
    vector<bool> products(10000, false);
    int numbers[] = {10, 100, 10};
    for (numbers[0] = 1; numbers[0] < 5000; numbers[0]++)
    {
        for (numbers[1] = 100; numbers[1] < 5000; numbers[1]++)
        {
            numbers[2] = numbers[0] * numbers[1];
            int length = 0;
            for (int i = 0; i < 3; i++)
            {
                int val = numbers[i];
                while (val > 10)
                {
                    val /= 10;
                    length++;
                }
                length++;
            }
            if (length != 9)
            {
                continue;
                cout << "lolz " << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;
            }
            vector<bool> isUsed(10, false);
            for (int i = 0; i < 3; i++)
            {
                int val = numbers[i];
                while (val > 10)
                {
                    isUsed[val % 10] = true;
                    val /= 10;
                }
                isUsed[val] = true;
            }
            bool isOk = true;
            for (int i = 1; i < isUsed.size(); i++)
            {
                if (isUsed[i] == false)
                {
                    isOk = false;
                    break;
                }
            }
            if (isOk && products[numbers[2]] == false)
            {
                total += numbers[2];
                cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;
                products[numbers[2]] = true;
            }
        }
    }
    cout << total << endl;
}
