#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float ans;       // ������� �������������� ����������� ������������������ �����
	int k = 0;       // ���������� ����� � ������������������
	float sum = 0;   // C���� �����������
	int flag = 1;
	cout << "������� ������������������ �����, ��� ����������� ����� ������������������ ������� -1" << endl;
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == -1)
		{
			break;
		}
		if (x < -1)
		{
			cout << " ������: ������ ������� ������������� ����� ";
			flag = -1;
			break;
		}
		++k;
		int f = 1;
		for (int i = 1; i <= x; ++i)
		{
			f *= i;
		}
		sum += f;
	}
	ans = sum / k;
	if (flag == 1 && sum != 0)
	{
		cout << "������� �������������� ����������� ������������������ ����� = " << ans;
	}
	return 0;
}
