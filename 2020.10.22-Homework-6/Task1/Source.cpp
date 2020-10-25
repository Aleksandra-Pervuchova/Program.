#include<iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout <<"0 - ����� �� ���������" << endl;
    cout <<"1 - �������� �������"<< endl;
	cout <<"2 - ������� ������"	<< endl;
	cout <<"3 - ���������, �������� �� ������ ������������"	<< endl;
	cout <<"4 - �������� ������ �� n ���������"	<< endl;
	cout <<"5 - ���������, ����� �� ������ ����� ������������, ���� �� ���� ������� ���� �������"  << endl;
}

bool symmetryCheck(ArrayList list)
{
	for (int i = 0; i < list.length(); ++i)
	{
		if (list.get(i) != list.get(list.length() -1 - i))
		{
			return false;
		}
		return true;
	}
}

void shift(ArrayList& list,int l)
{
	if (l > 0)
	{
		for (int i = 0; i < l; ++i)
		{
			list.set(0, list.get(list.length() - 1));
			for (int j = list.length() - 1; j > 0; --i)
			{
				list.set(j, list.get(j - 1));
			}
		}
	}
	else
	{
		for (int i = l; i < 0; ++i)
		{
			list.set(list.length() - 1, list.get(0));
			for (int j = 0; j < list.length() - 1; ++i)
			{
				list.set(j, list.get(j + 1));
			}
		}
	}
}

bool check(ArrayList& list)
{
	for (int i = 0; i < list.length(); ++i)
	{
		ArrayList b(list);
		b.remove(i);
		if (symmetryCheck(b))
		{
			return true;
		}
	}
	return false;
}

void processChoice(ArrayList& list, int choice)
{
	switch (choice)
	{
	case 1:
	{
		int x = 0;
		cin >> x;
		list.add(x);
	}
	break;
	case 2:
	{
		cout << list.toString() << endl;
	}
	break;
	case 3:
	{
		
		cout << "������ " << (symmetryCheck(list) == true ? "" : "��") << "������������" << endl;
	}
	break;
	case 4:
	{
		int n = 0;
		cin >> n;
		shift(list, n);
	}
	break;
	case 5:
	{
		cout << "������ " << (check(list) == true ? "" : "�� ") << "����� ����� ������������" << endl;
	}
	break;
	}
}

int main(int argc, char* argv[])
{
	setlocale (LC_ALL, "Russian");
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




















/*�������� ����������� ��* .h ���� : ��� ������ ��������.
�������� � ������� �����������.���������� ����� � ������ ������ ���� � ������������ � ������������.������� �� ����������� �������� �����(������� ������ � MS Teams)
�������� ����������� �����������.
� Source.cpp, ������ ��������� ������ :
-�������� �������, ��������� � ����������;
-������� ������;
-���������, �������� �� ������ ������������;
-����������� �������� ������ �� n ���������.n > 0 - ����� ������, n < 0 - ����� �����;
-���������, ����� �� ������ ����� ������������, ���� �� ���� ������� ���� �������.

�������� ������, ��� �� ��� ��� ������� �������.� ������ � ������������� �� ������ �������� ����� �������� �������.*/