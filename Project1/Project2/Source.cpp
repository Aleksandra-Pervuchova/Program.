#include<iostream>
using namespace std;
int main()
{
	int k = 1, a, b;
	cin >> a;
	cin >> b;
	while (b * k <= a)
	{
		++k;
	}
	--k;
	cout << k;
	return 0;
}