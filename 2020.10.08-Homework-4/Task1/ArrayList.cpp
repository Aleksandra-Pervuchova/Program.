#include"ArrayList.h"

ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10];
}

ArrayList::ArrayList(int cap)
{
	capacity = cap;
	count = 0;
	data = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] data;
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

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	data[count] = element;
	count++;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	if (index > count)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ArrayList::print()
{
	printf("[%d/%d]{", count, capacity);
	if (count == 0)
	{
		printf("EMPTY");
	}
	else
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
		}
	}
	printf("}\n");
}

bool ArrayList::remove(int index)
{
	for (int i = index; i < count; ++i)
	{
		data[i] = data[i + 1];
	}
	int* newData = new int[count - 1];
	for (int i = 0; i < count - 1; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
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


