#include<iostream>
using namespace std;

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "����\n0 - ����� �� ���������\n"
		<< "1 - �������� ����� � ������\n"
		<< "2 - ������� ������ �� �����\n"
		<< "3 - ����� ����� ������������� �������� ������� \n"
		<< "4 - ����� ����������� ������� ������� \n"
		<< "5 - ��������� ����� ��������� �������\n"
		<< "6 - ������� ������ � ������� �������" << endl;
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
		cout << arr[i] << (i != count - 1 ? "," : "");
	}
	cout << "}" << endl;
}


void printReverseArray(int*& arr, int& count, int& capacity)
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


int numberMaxElement(int*& arr, int& count)
{
	int numbermax = 0;
	for (int i = 1; i < count; ++i)
	{
		if (arr[i] > arr[numbermax])
		{
			numbermax = i;
		}
	}
	cout << "numbermax = " << numbermax << endl;
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

void processChoice(int*& arr, int& capacity, int& count)
{
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
}

int main(int argc, char* argv[])
{
	int capacity = 5;
	int* arr = new int[capacity];
	int count = 0;
	processChoice(arr, capacity, count);
	return 0;
}