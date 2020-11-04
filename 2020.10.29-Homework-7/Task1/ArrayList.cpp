#include "ArrayList.h"
#pragma once
ArrayList::~ArrayList()
{
	delete[] data;
}

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int [capacity] {0};
}

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
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
			add(i + list.count, get(i));
		}
		for (int i = 0; i < list.count; ++i)
		{
			add(i + index, get(i));
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
		add(index, element);
		return true;
	}
	return false;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; ++i)
	{
		if (get(i) == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	return false;
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
			add(i, get(i + 1));
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
		int temp = get(index1);
		add(index1, get(index2));
		add(index2, temp);
		return true;
	}
}

int ArrayList::length()
{
	return count;
}

void ArrayList::operator+=(int item)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = item;
	++count;
}

void ArrayList::operator-=(int item)
{
	for (int i = count - 1; i > 0; --i)
	{
		if (get(i) == item)
		{
			remove(i);
			break;
		}
	}
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	delete[] data;
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		data[i] = list.data[i];
	}
	return *this;
}

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList result(list);
	if (result.count == result.capacity)
	{
		result.expand();
	};
	result.data[result.count] = item;
	++result.count;
	return result;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList result(list);
	if (result.count == result.capacity)
	{
		result.expand();
	}
	for (int i = result.count - 1; i > 0; --i)
	{
		result.data[i] = result.data[i - 1];
	}
	result.data[0] = item;
	++result.count;
	return result;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList result(list2);
	while (result.count + list1.count > result.capacity)
	{
		result.expand();
	}
	for (int i = 0; i < list1.count; ++i)
	{
		result.data[i + list2.count] = list1.data[i];
		++result.count;
	}
	return result;
}

ArrayList operator-(const ArrayList& list, int item)
{
	ArrayList result(list);
	for (int i = result.count - 1; i >= 0; --i)
	{
		if (result.data[i] == item)
		{
			result.remove(i);
			break;
		}
	}
	return result;
}

ArrayList operator-(int item, const ArrayList& list)
{
	ArrayList result(list);
	for (int i = 0; i < result.count; ++i)
	{
		if (result.data[i] == item)
		{
			result.remove(i);
			break;
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	if (list.count > 0)
	{
		for (int i = 0; i < list.count - 1; ++i)
		{
			stream << list.data[i] << ", ";
		}
		stream << list.data[list.count - 1];
	}
	else
	{
		stream << 0;
	}
	return stream;
}
