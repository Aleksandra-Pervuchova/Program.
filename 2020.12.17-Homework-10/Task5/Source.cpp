#include<iostream>

using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int** data = new int* [n] {0};
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n] {0};
	}
	int k = 1;
	int i = 0;
	int j = 0;
	while (k < n*n + 1)
	{
		while (true)
		{
			if (k > n * n)
			{
				break;
			}
			data[i][j] = k;
			++j;
			++k;
			if ((j == n)||(data[i][j] != 0))
			{
				--j;
				++i;
				break;
			}
		}
		while (true)
		{
			if (k > n * n)
			{
				break;
			}
			data[i][j] = k;
			++i;
			++k;
			if ((i == n)||(data[i][j] != 0))
			{
				--i;
				--j;
				break;
			}
		}
		while (true)
		{
			if (k > n * n)
			{
				break;
			}
			data[i][j] = k;
			--j;
			++k;
			if ((j == -1)||(data[i][j] != 0))
			{
				++j;
				--i;
				break;
			}
		}
		while (true)
		{
			if (k > n * n)
			{
				break;
			}
			data[i][j] = k;
			--i;
			++k;
			if (data[i][j] != 0)
			{
				++i;
				++j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%4d", data[i][j]);
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