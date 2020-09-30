#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

void printMenu()
{
	cout << "Меню" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b (n, a, b вводится с клавиатуры)" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах. Если число элементов нечетно, последний элемент остается на своем месте" << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. m - индекс элемента, разделяющего  две половинки" << endl;
	cout << "6 - Вывести массив на экран" << endl;
}

void expandArray(int*& arr, int& capacity)
{
	int newCapacity = capacity * 2;
	int* temp = new int[newCapacity];
	for (int j = 0; j < capacity; ++j)
	{
		temp[j] = arr[j];
	}
	delete[] arr;
	arr = temp;
	capacity = newCapacity;
}

void printArray(int*& arr, int& count, int& capacity)
{
	cout << "[" << count << "/" << capacity << "]{";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << (i != count - 1 ? "," : "");
	}
	cout << "}" << endl;
}

int addRandomElements(int& capacity, int*& arr, int& count, int n, int min, int max)
{
	for (int i = 1; i <= n; ++i)
	{
		if (count == capacity)
		{
			expandArray(arr, capacity);
		}
		arr[count] = min + rand() % (max - min + 1);
		count++;
	}
	return 0;
}

void reverseArray(int*& arr, int& capacity, int& count)
{
	int* temp = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		temp[i] = arr[count - 1 - i];
	}
	delete[] arr;
	arr = temp;
}

void swapPairsArray(int& capacity, int& count, int*& arr)
{
	int* temp = new int[capacity];
	for (int i = 0; i < count - 1; i += 2)
	{
		temp[i] = arr[i + 1];
		temp[i + 1] = arr[i];
	}
	if (count % 2 != 0)
	{
		temp[count - 1] = arr[count - 1];
	}
	delete[] arr;
	arr = temp;
}

void shiftArray(int& capacity, int& count, int*& arr)
{
	int* temp = new int[capacity];
	for (int i = 1; i < count; ++i)
	{
		temp[i] = arr[i - 1];
	}
	temp[0] = arr[count - 1];
	delete[] arr;
	arr = temp;
}



void shiftPartsArray(int& count, int& capacity, int*& arr, int m)
{
	int* temp = new int[capacity];
	for (int i = 0; i < m; ++i)
	{
		temp[i] = arr[m - i - 1];
	}
	for (int i = m + 1; i < count; ++i)
	{
		temp[i] = arr[count - (i - m)];
	}
	temp[m] = arr[m];
	delete[] arr;
	arr = temp;
}

void processChoice(int*& arr, int& capacity, int& count, int choice, int& m, int& min, int& max, int& n)
{
		switch (choice)
		{
		case 1:
			cout << "Введите значения n, a, b" << endl;
			cin >> n >> min >> max;
			addRandomElements(capacity, arr, count, n, min, max);
			break;
		case 2:
			reverseArray(arr, capacity, count);
			break;
		case 3:
			swapPairsArray(capacity, count, arr);
			break;
		case 4:
			shiftArray(capacity, count, arr);
			break;
		case 5:
			cout << " Введите индекс элемента, разделяющего половинки массива" << endl;
			cin >> m;
			shiftPartsArray(count, capacity, arr, n);
			break;
		case 6:
			printArray(arr, count, capacity);
		}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int m, n, min, max;
	int choice = 0;
	int capacity = 5;
	int* arr = new int[capacity];
	int count = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(arr, capacity, count, choice, m, min, max, n);
		system("pause");
	} while (choice != 0);
	delete[] arr;
	return 0;
}