#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float ans;       // Среднее арифметическое факториалов последовательности чисел
	int k = 0;       // Количество чисел в последовательности
	float sum = 0;   // Cумма факториалов
	int flag = 1;
	cout << "Введите последовательность чисел, для обозначения конца последовательности введите -1" << endl;
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
			cout << " Ошибка: нельзя вводить отрицательные числа ";
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
		cout << "Среднее арифметическое факториалов последовательности чисел = " << ans;
	}
	return 0;
}
