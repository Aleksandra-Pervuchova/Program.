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
ѕосле реализации функций(там немного, честно), нужно решить с использованием вашей структуры следующие задачи.
1).ƒобавить в список 10 случайных положительных двузначных чисел и вывести список
2).ƒобавить в список 10 случайных отрицательных двузначных чисел и вывести список
3).ѕомен€ть местами первый минимальный и последний максимальный элемент и вывести список
4).ѕеремешать все элементы массива и вывести массив.
5).«аменить каждый отрицательный элемент массива на 0.*/