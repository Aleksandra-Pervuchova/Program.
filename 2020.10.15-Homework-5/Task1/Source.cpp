#include <iostream>
#include "ArrayList.h"
#include <random>

using namespace std;

int main()
{
	int k = 10;
	ArrayList a;
	/*for (int i = 0; i < k; ++i)
	{
		a.add(rand() % 90 + 10);
	}
	cout << a.toString();*/

	for (int i = 0; i < k; ++i)
	{
		a.add(rand() % 90 - 99);
	}
	cout << a.toString();

	int min = 0;
	int max = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) < a.get(min))
		{
			min = i;
		}
	}
	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) >= a.get(max))
		{
			max = i;
		}
	}
	a.swap(min, max);

	for (int i = 0; i < a.length(); ++i)
	{
		int j = rand() % (i + 1);
		a.swap(i, j);
	}
	cout << a.toString();

	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) < 0)
		{
			a.set(i, 0);
		}
	}

	return EXIT_SUCCESS;
}



/*
����� ���������� �������(��� �������, ������), ����� ������ � �������������� ����� ��������� ��������� ������.
1).�������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������
2).�������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������
3).�������� ������� ������ ����������� � ��������� ������������ ������� � ������� ������
4).���������� ��� �������� ������� � ������� ������.
5).�������� ������ ������������� ������� ������� �� 0.*/