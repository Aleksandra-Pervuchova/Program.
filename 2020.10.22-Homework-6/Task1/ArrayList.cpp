#include "ArrayList.h"
#pragma once

ArrayList::~ArrayList()
{
	delete[] data;
	if (str != nullptr)
	{
		delete[] str;
	}
}

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	str = nullptr;
	data = new int[capacity];
	for (int i = 0; i < count; data[i] = list.data[i], ++i);
}

void ArrayList::expand()
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

int ArrayList::numLength(int number)
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

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addToStr(int& index, int number)
{
	int h = numLength(number);
	if (number < 0)
	{
		for (int i = 0; i < h - 1; ++i)
		{
			int digit = number % 10;
			str[index + h - 1 - i] = '0' - digit;
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
	index += h;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	++count;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (index > count)
	{
		return false;
	}
	else
	{
		if (count == capacity)
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
}

bool ArrayList::addAll(ArrayList& list)
{
	while (count + list.count >= capacity)
	{
		expand();
	}
	for (int i = 0; i < list.count; ++i)
	{
		add(list.get(i));
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (index > count)
	{
		return false;
	}
	else
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
	if (index < count)
	{
		return data[index];
	}
	return -1;
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
	if (str != nullptr)
	{
		delete[]str;
		str = nullptr;
	}
	int length = 7 + numLength(count) + numLength(capacity) + ((count - 1) * 2);
	for (int i = 0; i < count; ++i)
	{
		length += numLength(data[i]);
	}
	str = new char[length];
	int index = 0;
	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, capacity);
	addToStr(index, ']');
	addToStr(index, ' ');
	addToStr(index, '{');
	for (int i = 0; i < count - 1; ++i)
	{
		addToStr(index, data[i]);
		addToStr(index, ',');
		addToStr(index, ' ');
	}
	addToStr(index, data[count - 1]);
	addToStr(index, '}');
	addToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	if (index >= count)
	{
		return false;
	}
	else
	{
		for (int i = index; i < count - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		--count;
		return true;
	}
}

bool ArrayList::swap(int index1, int index2)
{
	if ((index1 >= count) & (index2 >= count))
	{
		return false;
	}
	else
	{
		int temp = data[index1];
		data[index1] = data[index2];
		data[index2] = temp;
		return true;
    }
}

int ArrayList::length()
{
	return count;
}

