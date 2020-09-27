#include <iostream>
using namespace std;
int main()
{
	int i, j, k = 0;
	cin >> i;
	for (j = 1; j * j <= i; ++j)
	{
		if (i % j == 0)
		{
			++k;
		}
	};
	if (i != 1)
	{
		cout << k * 2;
	}
	else
	{
		cout << "1";
	}
	return 0;
}