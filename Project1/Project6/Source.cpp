#include <iostream>
using namespace std;
int main()
{
	int f = 1, x = 2, n;
	cin >> n;
	while (x <= n)
	{
		f = x * f;
		x = x + 1;
	}
	cout << f;
	return 0;
}