#include <iostream>
#include <random> 
#include <ctime>
using namespace std;

void printMenu()
{
	setlocale(LC_ALL, "Russian");
	cout << "����\n0 - ����� �� ���������\n"
		<< "1 - �������� � ������ n ��������� ����� � ���������� �� a �� b (n, a, b �������� � ����������)\n"
		<< "2 - ���������� ������\n"
		<< "3 - �������� �������� ������� ������� � �����. ���� ����� ��������� �������, ��������� ������� �������� �� ����� �����\n"
		<< "4 - ����������� ����� ������ �� 1\n"
		<< "5 - ���������� ��� ��������� �������. m - ������ ��������, ������������  ��� ���������\n"
		<< "6 - ������� ������ �� �����" << endl;
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

int random(int& capacity, int*& arr, int& count, int n, int a, int b)
{
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
		temp[i + 1] = arr[i];
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

void processChoice(int*& arr, int& capacity, int& count)
{
	int choice = -1;
	int m, n, a, b;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� �������� n, a, b" << endl;
			cin >> n >> a >> b;
			random(capacity, arr, count, n, a, b);
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
			cout << " ������� ������ ��������, ������������ ��������� �������" << endl;
			cin >> m;
			if (m >= count)
			{
				cout << "������: ��� ��������� � ����� ��������" << endl;
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

int main(int argc, char* argv[])
{
	int capacity = 5;
	int* arr = new int[capacity];
	int count = 0;
	processChoice(arr, capacity, count);
}