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

void addRandomElements(int& capacity, int*& arr, int& count, int n, int min, int max)
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
}

void reverseArray(int*& arr, int& count)
{
	int temp;
	for (int i = 0; i <= count / 2 ; ++i)
	{
		temp = arr[i];
		arr[i] = arr[count - 1 - i];
		arr[count - 1 - i] = temp;
	}
}

int swapPairsArray(int*& arr, int& count)
{
	int temp;
	for (int i = 0; i < count - 1; i += 2)
	{
		temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	return 0;
}

int shiftArray(int*& arr, int& count)
{
	int temp = arr[count - 1];
	for (int i = count - 1; i > 0; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
	return 0;
}



int shiftPartsArray(int*& arr, int& count, int m)
{
	int temp;
	for (int i = 0; i <= m / 2; ++i)
	{
		temp = arr[i];
		arr[i] = arr[m - i - 1];
		arr[m - i - 1] = temp;
	}
	for (int i = m + 1; i <= (count + m) / 2; ++i)
	{
		temp = arr[i];
		arr[i] = arr[count - (i - m)];
		arr[count - (i - m)] = arr[temp];
	}
	return 0;
}

void processChoice(int*& arr, int& capacity, int& count, int choice)
{
	int n, min, max, m;
		switch (choice)
		{
		case 1:
			cout << "Введите значения n, a, b" << endl;
			cin >> n >> min >> max;
			addRandomElements(capacity, arr, count, n, min, max);
			break;
		case 2:
			reverseArray(arr, count);
			break;
		case 3:
			swapPairsArray( arr, count);
			break;
		case 4:
			shiftArray(arr, count);
			break;
		case 5:
			cout << " Введите индекс элемента, разделяющего половинки массива" << endl;
			cin >> m;
			shiftPartsArray(arr, count, m);
			break;
		case 6:
			printArray(arr, count, capacity);
		}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int capacity = 5;
	int count = 0;
	int* arr = new int[capacity];
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(arr, capacity, count, choice);
		system("pause");
	} while (choice != 0);
	delete[] arr;
	return 0;
}