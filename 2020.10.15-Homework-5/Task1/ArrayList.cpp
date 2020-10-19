#include "ArrayList.h"

ArrayList::~ArrayList()
{
	delete[] data;
}

void ArrayList::expand()
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
		capacity *= 2;
		delete[] data;
		data = newData;
	}
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

bool ArrayList::add(int element)
{
	/*if (count = capacity)
	{
		expand();
	}*/
	data[count] = element;
	++count;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (count = capacity)
	{
		expand();
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	++count;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	while (count + list.count >= capacity)
	{
		expand();
	}
	for (int i = 0; i < list.count; ++i)
	{
		data[count + i] = list.data[i];
	}
	count += list.count;
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	while (count + list.count >= capacity)
	{
		expand();
	}
	for (int i = count - 1; i >= index; --i)
	{
		data[i + list.count] = data[i];
	}
	for (int i = 0; i < list.count; ++i)
	{
		data[i + index] = list.data[i];
	}
	count += list.count;
	return true;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if (index <= count)
	{
		return data[index];
	}
	else
	{
		return -1;
	}
}

bool ArrayList::set(int index, int element)
{
	if (index < count)
	{
		data[index] = element;
		return true;
	}
	return false;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	if (count = 0)
	{
		return true;
	}
	return false;
}

char* ArrayList::toString()
{
	int length = 7 + numLength(count) + numLength(capacity) + (count - 1) * 2;
	for (int i = 0; i < count; ++i)
	{
		length += numLength(data[i]);
	}
	str = new char[length];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');
	for (int i = 0; i < count - 1; ++i)
	{
		addNumberToStr(index, data[i]);
		addSymbolToStr(index, ',');
		addSymbolToStr(index, ' ');
	}
	addNumberToStr(index, data[count - 1]);
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	for (int i = index; i < count - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	--count;
	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
	return true;
}

int ArrayList::length()
{
	return count;
}