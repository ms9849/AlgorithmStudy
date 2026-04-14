#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN;
	long long iDp[101] = {};

	cin >> iN;

	iDp[0] = 0;
	iDp[1] = 1;

	for (int i = 2; i <= iN; ++i)
	{
		iDp[i] = iDp[i - 1] + iDp[i - 2];
	}

	cout << iDp[iN];

	return 0;
}