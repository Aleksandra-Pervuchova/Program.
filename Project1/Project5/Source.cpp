#include <iostream>
using namespace std;
int main()
{
	int i, j, k = 0;
	cin >> i;
	for (j = 1; j <= i; ++j)
	{
		if (i % j == 0)
		{
			++k;
		}
	}
	cout << k;
	return 0;
}