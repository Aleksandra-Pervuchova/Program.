#include <iostream>
using namespace std;
int main()
{
	int i, x, a, b, k=0;
	cin >> x;
	for (i = 0; i <= 999999; ++i)
	{
		a = i % 10 + (i % 100) / 10 + (i % 1000) / 100;
		b = (i /1000) % 10 + (i / 10000) % 10 + i / 100000;
		if (a == b and a == x)
		{
			++k;
		}
	}
	cout << k;
	return 0;
}