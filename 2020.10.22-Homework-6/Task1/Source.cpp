#include<iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "Меню" << endl;
	cout <<"0 - Выйти из программы" << endl;
    cout <<"1 - Добавить элемент"<< endl;
	cout <<"2 - Вывести массив"	<< endl;
	cout <<"3 - Проверить, является ли массив симметричным"	<< endl;
	cout <<"4 - Сдвинуть массив на n элементов"	<< endl;
	cout <<"5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент"  << endl;
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
		
		cout << "Массив " << (symmetryCheck(list) == true ? "" : "не") << "симметричный" << endl;
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
		cout << "Массив " << (check(list) == true ? "" : "не ") << "может стать симметричным" << endl;
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




















/*Остается ограничение на* .h файл : его нельзя изменять.
Привести в порядок репозиторий.Именование папок и файлов должно быть в соответствии с требованиями.Удалить из репозитория ненужные папки(вопросы писать в MS Teams)
Добавить конструктор копирования.
В Source.cpp, решить следующие задачи :
-добавить элемент, введенный с клавиатуры;
-вывести массив;
-проверить, является ли массив симметричным;
-циклический сдвинуть массив на n элементов.n > 0 - сдвиг вправо, n < 0 - сдвиг влево;
-проверить, может ли массив стать симметричным, если из него удалить один элемент.

Отдельно замечу, что на это раз дедлайн жесткий.Я слегка в растерянности по поводу ожидания ваших домашних заданий.*/