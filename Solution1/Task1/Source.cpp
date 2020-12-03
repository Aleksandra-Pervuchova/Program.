#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double myFunction(float x, int n)
{
	double result = 0;
	int j = 1;	
	double d = x;
	result = x;
	while (true)
	{
		j += 2;
		d *= (-1) * x * x /j/(j-1);
		result += d;

		if (result * (10 ^ n) - floor(result * (10 ^ n)) > 0)
		{
			break;
		}
	}
	return result;
}

int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << sin(x) << endl;
	cout << myFunction(x, n) << endl;
	return 0;

}/*fabs(result * (10 ^ n)) - floor(fabs(result * (10 ^ n))) > 0*/