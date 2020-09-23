#include <iostream>
using namespace std;
int main()
{
	int x, n, i, res = 1;
	cin >> x >> n;
	for (i = 1; i <= n; ++i)
	{
		res *= x;
	}
	cout << res;
	return 0;
}