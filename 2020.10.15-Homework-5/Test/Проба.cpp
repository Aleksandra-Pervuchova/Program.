#include <iostream>

using namespace std;
int main()
{
	/*int result = 0;
	int number = 0;
	cin >> number;
	if (number >= 0)
	{
		result = 1;
		while (number > 9)
		{
			number /= 10;
			++result;
		}
	}
	else
	{
		result = 2;
		while (number < -9)
		{
			number /= 10;
			++result;
		}
	}
	cout << result;*/

	/*int* arr = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 90 - 99;
		cout << arr[i];
	}*/
	int x = 0;
	cin >> x;
	cout << x / 10;
}