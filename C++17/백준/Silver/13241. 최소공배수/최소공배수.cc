#include <iostream>

using namespace std;

long long GCD(int a, int b)
{
	long long r = a % b;

	if (r == 0)
		return b;
	else
		return GCD(b, r);
}

int main(void* pArg)
{
	long long iA{}, iB{};

	cin >> iA >> iB;

	cout << iA * iB / GCD(iA, iB);

	return 0;
}