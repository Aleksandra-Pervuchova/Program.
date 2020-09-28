#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout<< "Меню\n0 - Выход из программы\n"
		<< "1 - Добавить в массив n случайных чисел в промежутке от a до b (n, a, b вводится с клавиатуры)\n"
		<< "2 - Развернуть массив\n"
		<< "3 - Поменять элементы массива местами в парах. Если число элементов нечетно, последний элемент остается на своем месте\n"
		<< "4 - Циклический сдвиг вправо на 1\n"
		<< "5 - Развернуть две половинки массива\n" 
		<< "6 - Вывести массив на экран" << endl;
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

int random(int& capacity, int*& arr, int& count)
{
	int a, b, n;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
	{
		if (count == capacity)
		{
			expandArray(arr, capacity);
		}
		arr[count] = a + rand() % (b - a + 1);
		count++;
	}
	return 0;
}

void reverse(int*& arr, int& capacity, int& count)
{
	int* temp = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		temp[i] = arr[count - 1 - i];
	}
	delete[] arr;
	arr = temp;
}

void pairChange(int& capacity, int& count, int*& arr)
{
	int* temp = new int[capacity];
	for (int i = 0; i < count - 1; i += 2)
	{
		temp[i] = arr[i + 1];
		temp[i + 1] =arr[i] ;
	}
	if (count % 2 != 0)
	{
        temp[count - 1] = arr[count - 1];
	}
	delete[] arr;
	arr = temp;
}

void shift(int& capacity, int& count, int*& arr)
{
	int* temp = new int[capacity];
	for (int i = 1; i < count; ++i)
	{
		temp[i] = arr[i - 1];
	};
	temp[0] = arr[count - 1];
	delete[] arr;
	arr = temp;
}



void reversalHalf(int& count, int& capacity, int*& arr, int n)
{
	int* temp = new int[capacity];
	for (int i = 0; i < n; ++i)
	{
		temp[i] = arr[n - i - 1];
	 }
	for (int i = n + 1; i < count; ++i)
	{
		temp[i] = arr[count - (i - n)];
	}
	temp[n] = arr[n];
	delete[] arr;
	arr = temp;
}

int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "Russian");
	cout << "Введите значения элементов массива, для прекращения ввода введите 0" << endl;
	int capacity = 5;
	int* arr = new int[capacity];
	int count = 0;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (count == capacity)
		{
			expandArray(arr, capacity);
		}
		arr[count] = x;
		count++;
	}

	int choice = -1;
	int n = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			random(capacity, arr, count);
			break;
		case 2:
			reverse(arr, capacity, count);
			break;
		case 3:
			pairChange(capacity, count, arr);
			break;
		case 4:
			shift(capacity, count, arr);
			break;
		case 5:
			cout << " Введите индекс элемента, разделяющего половинки массива" << endl;
			cin >> n;
			if (n >= count || n < 0)
			{
				cout << "Ошибка: нет элементов с таким индексом" << endl;
				break;
			}
			reversalHalf(count, capacity, arr, n);
			break;
		case 6:
			printArray(arr, count, capacity);
		}
		system("pause");
	}
}