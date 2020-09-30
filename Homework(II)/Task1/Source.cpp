#include<iostream>
using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить число в массив" << endl;
	cout << "2 - Вывести массив на экран" << endl;
	cout << "3 - Найти номер максимального элемента массива" << endl;
	cout << "4 - Найти минимальный элемент массива" << endl;
	cout << "5 - Посчитать сумму элементов массива" << endl;
	cout << "6 - Вывести массив в оратном порядке" << endl;
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

int addElement(int*& arr, int& capacity, int& count, int element)
{
	cin >> element;
	if (count == capacity)
	{
		expandArray(arr, capacity);
	}
	arr[count] = element;
	count++;
	return 0;
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


void reversePrintArray(int*& arr, int& count, int& capacity)
{
	cout << "[" << count << "/" << capacity << "]{";
	for (int i = count - 1; i >= 0; --i)
	{
		cout << arr[i] << (i != 0 ? "," : "");
	}
	cout << "}" << endl;
}

int minElement(int*& arr, int& count)
{
	int min = arr[0];
	for (int i = 1; i < count; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	cout << "min = " << min << endl;
	return min;
}


int maxIndex(int*& arr, int& count)
{
	int maxindex = 0;
	for (int i = 1; i < count; ++i)
	{
		if (arr[i] > arr[maxindex])
		{
			maxindex = i;
		}
	}
	cout << "maxindex = " << maxindex << endl;
	return 0;
}


int sumArray(int*& arr, int& count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

void processChoice(int*& arr, int& capacity, int& count, int choice, int& element)
{
	    switch (choice)
		{
		case 1:
			addElement(arr, capacity, count, element);
			break;
		case 2:
			printArray(arr, count, capacity);
			break;
		case 3:
			maxIndex(arr, count);
			break;
		case 4:
			minElement(arr, count);
			break;
		case 5:
			cout << "sum = " << sumArray(arr, count) << endl;
			break;
		case 6:
			reversePrintArray(arr, count, capacity);
			break;
		}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int capacity = 5;
	int count = 0;
	int element;
	int* arr = new int[capacity];
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(arr, capacity, count, choice, element);
		system("pause");
	} while (choice != 0);
	delete[] arr;
	return 0;
}