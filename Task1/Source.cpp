#include<iostream>
using namespace std;

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "Меню\n 0 - Выход из программы\n"
         << "1- Добавить число в массив\n"
         << "2- Вывести массив на экран\n"
         << "3- Найти номер максимального элемента массива \n" 
         << "4- Найти минимальный элемент массива \n" 
         << "5- Посчитать сумму элементов массива\n" 
         << "6- Вывести массив в оратном порядке" << endl;
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

int inputElement(int*& arr, int& capacity, int& count)
{
	int x;
	cin >> x;
	if (count == capacity)
	{
		expandArray(arr, capacity);
	}
		arr[count] = x;
		count++;	
	return 0;
}

void printArray(int*& arr, int& count, int& capacity)
{
	cout << "[" << count << "/" << capacity << "]{";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i]<< (i!=count-1 ? "," : "") ;
	}
	cout << "}" << endl;
}


void printReverseArray(int*& arr, int& count, int& capacity)
{
	cout << "[" << count << "/" << capacity << "]{";
	for (int i = count-1; i >= 0; --i)
	{
		cout << arr[i]<< (i !=0 ? "," : "") ;
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


int numberMaxElement(int*& arr, int& count)
{
	int numbermax = 0, max = arr[0];
	for (int i = 1; i < count; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			numbermax = i;
		}
	}
	cout << "numbermax = "<< numbermax << endl;
	return numbermax;
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
			expandArray( arr, capacity);
		}
		arr[count] = x;
		count++;
	}
	system("cls");
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			inputElement(arr, capacity, count);
			break;
		case 2:
			printArray(arr, count, capacity);
			break;
		case 3:
			numberMaxElement(arr, count);
			break;
		case 4:
			minElement(arr, count);
			break;
		case 5:
			cout << "sum = " << sumArray(arr, count) << endl;
			break;
		case 6:
			printReverseArray(arr, count, capacity);
			break;
		}
		system("pause");
	}
	return 0;
}