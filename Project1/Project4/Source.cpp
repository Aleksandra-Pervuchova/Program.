#include <iostream>
using namespace std;
int main()
{
	int x, i, j, k = 0;
	cin >> x;
	for (i = 2; i <= x; ++i)
	{
		for (j = 2; j <= i; ++j)
		{
			if (i % j == 0)
			{
				++k;
			}
		}
		if (k == 1)
		{
			cout << i << " ";
		}
		k = 0;
	}
	return 0;
}