#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"
using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
}


void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		int x = 0;
		std::cin >> x;
		a.add(x);
	}
	break;
	case 3:
	{
		int x = 0;
		int i = 0;
		std::cin >> i >> x;
		a.add(i, x);
	}
	break;
	case 4:
	{
		int i = 0;
		std::cin >> i;
		a.remove(i);
	}
	break;
	case 5:
	{
		int x = 0;
		std::cin >> x;
		a.indexOf(x);
	}
	break;
	case 6:
	{
		ArrayList p;
		int x = 0;
		int k = 0;
		std::cin >> k;
		p.count = k;
		p.data = new int[k];
		for (int i = 0; i < k; ++i)
		{
			std::cin >> x;
			p.data[i] = x;
		}
		a.add(p);
		delete[] p.data;
	}
	break;
	case 7:
	{
		ArrayList p;
		int x = 0;
		int i = 0;
		int k = 0;
		std::cin >> k;
		std::cin >> i;
		p.count = k;
		p.data = new int[k];
		for (int i = 0; i < k; ++i)
		{
			std::cin >> x;
			p.data[k] = x;
		} 
		a.addAll(i, p);
		delete[] p.data;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}