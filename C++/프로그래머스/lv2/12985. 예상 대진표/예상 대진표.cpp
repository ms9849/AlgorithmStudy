#include <iostream>

using namespace std;
int solution(int n, int a, int b)
{
	int answer = 0;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int cnt = 1;
	while (1)
	{
		if ((a + 1 == b &&
			a % 2 == 1))
			break;

		if (a % 2 == 1)
		{
			a /= 2;
			a += 1;
		}
		else
			a /= 2;

		if (b % 2 == 1)
		{
			b /= 2;
			b += 1;
		}
		else
			b /= 2;

		cnt++;
	}

	return cnt;
}
