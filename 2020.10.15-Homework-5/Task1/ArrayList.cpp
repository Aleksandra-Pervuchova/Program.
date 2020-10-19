#include "ArrayList.h"
void expand()
{
	if (count = capacity)
	{

	}
}
void expand(int*& data, int& capacity)
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	capacity *= 2;
	delete[] data;
	data = newData;
}

int ArrayList:: numLength(int number)
{
	int result = 0;
	if (number >= 0)
	{
		int result = 1;
		while (number > 9)
		{
			number /= 10;
			++result;
		}
	}
	else
	{
		int result = 2;
		while (number < 9)
		{
			number /= 10;
			++result;
		}
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	for (int i = 0; i < length; ++i)
	{
		int digit = number %= 10;
		str[index + length - 1 - i] = '0' + digit;
		digit /= 10;
	}
	index += length;
}

