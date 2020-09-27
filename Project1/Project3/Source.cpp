#include <iostream>
const int W = 8;
using namespace std;
int main(int argc, char* argv[])
{
	int a, b, c, d, e, f, k=0, i;
	for (i = 1; i <= W+1; ++i)
	{
		k += i;
	}
	k *= k;
	setlocale(LC_ALL, "Russian");
	cout << k << " номеров счастливых билетов с суммой 8: ";
	for (a = 0; a <= W; ++a)
	{
		for (b = 0; b <= W-a; ++b)
		{
			for (d = 0; d <= W; ++d)
			{
				for (e = 0; e <= W-d; ++e)
				{
					{							
						cout << a << b << W - a - b << d << e << W - d - e << ", ";
					};
				};
			};
		};
	};
	return 0;
}