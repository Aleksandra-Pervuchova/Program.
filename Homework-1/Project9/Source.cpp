#include <iostream>
using namespace std;
int main()
{
	int n, a = 1, aa = 1;
	cin >> n;
	a = a << n;
	aa = aa << n + 1;
	a = ~a;
	cout << a + aa;
	return 0;
}