#include <iostream>
#include <string.h>

using namespace std;

int numLength(int number)
{
	int result = 0;
	if (number >= 0)
	{
		result = 1;
		while (number > 9)
		{
			number /= 10;
			++result;
		}
	}
	else
	{
		result = 2;
		while (number < -9)
		{
			number /= 10;
			++result;
		}
	}
	return result;
}

int main()
{
	int x = -16;
	int y = x % 10;
	/*int index = 0;
	int number = 0;
	char* str = new char[30];
	cin >> number;
	int h = numLength(number);
	if (number < 0)
	{
		for (int i = 0; i < h - 1; ++i)
		{
			int digit = number % 10;
			str[index + h - 1 - i] = '0' + digit;
			number /= 10;
		}
		str[index] = '-';
	}
	else
	{
		for (int i = 0; i < h; ++i)
		{
			int digit = number % 10;
			str[index + h - 1 - i] = '0' + digit;
			number /= 10;
		}
	}
	cout << str;
	delete[] str;*/
	cout << y;
}
