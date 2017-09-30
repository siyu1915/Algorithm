#include <iostream>

int Sqrt(int x)
{
	long long i = 0;
	long long j = x / 2 + 1;
	while (i <= j)
	{
		long long mid = (i + j) / 2;
		long long sq = mid * mid;
		if (sq > x) j = mid - 1;
		if (sq < x) i = mid + 1;
		if (sq == x) return mid;
	}
}

int main()
{
	int x = 9;
	int r = Sqrt(x);
	std::cout << r << std::endl;
	return 0;
}
