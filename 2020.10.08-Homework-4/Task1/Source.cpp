#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"
using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
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
		
		int x = 0;
		int k = 0;
		std::cin >> k;
		ArrayList p(k);
		for (int i = 0; i < k; ++i)
		{
			std::cin >> x;
			p.data[i] = x;
			++p.count;
		}
		a.add(p);
	}
	break;
	case 7:
	{
		int x = 0;
		int index = 0;
		int k = 0;
		std::cin >> k;
		std::cin >> index;
		ArrayList p(k);
		for (int j = 0; j < k; ++j)
		{
			std::cin >> x;
			p.data[j] = x;
			++p.count;
		} 
		a.addAll(index, p);
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