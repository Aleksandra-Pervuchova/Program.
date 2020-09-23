#include<iostream>
using namespace std;
int main()
{
	int a, aa, res;
	cin >> a;
	aa = a * a;
	res = (aa + 1) * (aa + a) + 1;
	cout << res;
	return 0;
}