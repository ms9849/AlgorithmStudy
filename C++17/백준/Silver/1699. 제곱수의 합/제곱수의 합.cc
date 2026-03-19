#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iDp[100001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN;
	cin >> iN;

	for (int i = 0; i <= 100000; ++i)
	{
		iDp[i] = 100001;
	}

	for (int i = 1; i*i <= 100000; ++i)
	{
		iDp[i * i] = 1;
	}

	for (int i = 2; i <= iN; ++i)
	{
		for (int j = 1; j*j <= i; j++)
		{
			iDp[i] = min(iDp[i - j * j] + iDp[j*j], iDp[i]);
		}
	}

	cout << iDp[iN];

	return 0;
}