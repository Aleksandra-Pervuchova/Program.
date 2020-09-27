#include <iostream>
const int W = 9;
using namespace std;
int main()
{
	int a, b, c, d, e, f, k=0, i;
	for (i = 1; i <= W; ++i)
	{
		k += i;
	}
	k *= k;
	setlocale(LC_ALL, "Russian");
	cout << k << " номеров счастливых билетов с суммой 8: ";
	for (a = 0; a <= W; ++a)
	{
		for (b = 0; b <= W; ++b)
		{
			for (c = 0; c <= W; ++c)
			{
				for (d = 0; d <= W; ++d)
				{
					for (e = 0; e <= W; ++e)
					{
						for (f = 0; f <= W; ++f)
						{
							if (a + b + c == d + e + f && a + b + c == W - 1)
							{							
								cout << a << b << c << d << e << f << ", ";
							};
						};
					};
				};
			};
		};
	};
	return 0;
}