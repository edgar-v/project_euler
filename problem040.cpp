#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

vector<int> getDigits(int number)
{
	vector<int> digits;
	while (number >= 10)
	{
		digits.push_back(number % 10);
		number /= 10;
	}
	digits.push_back(number);
	vector<int> rdigits;
	for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
	{
		rdigits.push_back(*it);
	}
	return rdigits;
}

int main()
{
	int total = 1;
	int number = 1;
	vector<int> decimals;
	do
	{
		vector<int> digits = getDigits(number);
		for (int j = 0; j < digits.size(); j++)
		{
			decimals.push_back(digits[j]);
		}
		number++;
	} while (decimals.size() < 1000001);
	for (int i = 0; i <= 6; i++)
	{
		total *= decimals[pow(10, i)-1];
	}
	cout << total << endl;
}
