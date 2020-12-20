#include<iostream>

using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int** data = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		for (int j = 0; j <= i; ++j)
		{
			data[i][j] = j + 1;
			k = j;
		}
		for (int j = k + 1; j < n; ++j)
		{
			data[i][j] = k + 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%3d", data[i][j]);
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	return 0;
}