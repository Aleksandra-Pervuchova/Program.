#include<iostream>
#include<string>
using namespace std;

void resolveError(int errorCode)
{
	if (errorCode == 0)
	{
		return;
	}
	if (errorCode == 1)
	{
		if (rand() % 2 == 1)
		{
			cout << "� ���������, ������������� ����������� ��������� �� ��������� �� ������� ���� ������. ����������, ��������� ������� �����. ������ ����� �� ������ ��������� �������." << endl;
		}
		else
		{
			cout << "���������� �� ������������ ������� � ������." << endl;
		}
	}
	if (errorCode == 2)
	{
		if (rand() % 2 == 1)
		{
			cout << "����������, ���������� ������ ����� ������. ������ ����� �� ����� ��������� ��������� �������" << endl;
		}
		else
		{
			cout << "��� ����� ����, �� ��������� �� ������� ������� ���� ������. ������������ �� ������������ �����" << endl;
		}
	}
	if (errorCode == 3)
	{
		if (rand() % 2 == 1)
		{
			cout << "�������� ���� ��������� �� ������������ ����������. ����������, ��������� �������. ����� �� ������ ��������� �������, �������� �� ����" << endl;
		}
		else
		{
			cout << "� ���������, ��������� �� ����� ������� ���� �����. ���������� ��������� �� ������ ����� ����� ���������� � ������ �������, �������� �� ����" << endl;
		}
	}
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isLetter(char symbol)
{
	return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || (symbol >= '�' && symbol <= '�') || (symbol >= '�' && symbol <= '�') || (symbol == '�') || (symbol >= '�' && symbol <= '�') || (symbol >= '�' && symbol <= '�') || (symbol == '�');
}

int readInt(long long& intNum)
{
	char c = ' ';
	while (true)
	{
		cin.get(c);
		if (isDigit(c))
		{
			intNum = intNum * 10 + c - '0';
		}
		if (c == ' ')
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 1;
		}
		if (isLetter(c))
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 2; 
		}
		if ((c == '\n' || c == '\t' || c == '\0' || c == '\r') && (intNum != 0))
		{
			return 0;
		}
		if (!isDigit(c))
		{
			cin.ignore(32767, '\n');
			intNum = 0;
			return 3;
		}
	}
}

double readDouble(double& doubleNum)
{
	bool flag = false;
	double k = 0.1;
	char c = ' ';
	while (true)
	{
		cin.get(c);
		if (isDigit(c))
		{
			if (flag)
			{
				doubleNum += (c - '0')*k;
				k/10;
			}
			else
			{
				doubleNum = doubleNum * 10 + c - '0';
			}                                         // doubleNum = doubleNum * 10 + c - '0';
		}
		if (c == '.' && doubleNum != 0)
		{
			flag = true;
		}
		if (c == ' ')
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 1;
		}
		if (isLetter(c))
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 2;
		}
		if ((c == '\n' || c == '\t' || c == '\0' || c == '\r') && (doubleNum != 0))
		{
			return 0;
		}
		if (!isDigit(c) && c != '.')
		{
			cin.ignore(32767, '\n');
			doubleNum = 0;
			flag = false;
			k = 0.1;
			return 3;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long intNum = 0;
	int resultCode = -1;
	cout << "������� ����� �����" << endl;
	while (resultCode != 0)
	{
		resultCode = readInt(intNum);
		resolveError(resultCode);
	}
	double doubleNum = 0;
	resultCode = -1;
	cout << "������� ������������ �����" << endl;
	while (resultCode != 0)
	{
		resultCode = readDouble(doubleNum);
		resolveError(resultCode);
	}
	double x = intNum * 1.0;
	double result = x + doubleNum;
	cout << "intNum + doubleNum = " << result << endl;
}






/*�� ������ � �������� �������� : ���� ��������� ������������ ���������� 
"���� ��� ��� ���� � ���� ����� ������������".� �������� ������������ ������ 
����������� ���������� �� ������ �������� ���������, ������� ���������� ��� �����(long long + double) 
� ������� ���������.������������ ���������� ������� � �� ����� ������ � "����� ������ ������������" 
� �� ����� ����� ��������� "������ ��� ������ ����, ���� ��������� ��� ������".� ��� ������������ ����� ���������,
�� ����� �������.��������� ���� ��� �������� ���� ��� � ����� ���������� �� ��� ������ �� �����.� ������ ������������� ����� 
��������� ������ ���������� �� �������������� ������������ ����������� ��������� ������������ ������� ����� ����� � ��������� ���������
������������ �� ���������� �������� � ���������� �����.������������ ���������� ������� � � ������ � ������ ������ ����� ���������� 
������ ��������� ������ ���� "523456", � � ������ � ������� ������ "53216.125" (������������ ��� � ������ - ��� �� ������ ����� ���� 
������ ����� �������).� ����� � ���� �������������� ������� ��������� ������� :

void resolveError(int errorCode); -��������� ��������� �� ���� ����� "errorCode" � ������� �� ����� ����� ������.
����������� ������� ���� ������ ������ ����� ��� ������� ��� ��������� ������������ � ������ �� ��� ������ ���������� ��������� �������.
���������� ���������� ������� ��� ������ string.
int readInt(long long& number); -��������� ����� - �� ������� ������ ���, ��� � number �������� ��������� ����� �����, ���� ���������� 
� ���� 0 � ���������� ��� ������.
double readDouble(double& double); -��������� ��������� double.��� � ���������� ������� ��� ����� ������� ��� ������.

����� ���� ������� � ��� ��� ����� ���� ����� ������ ������������� � ���������� �������.*/