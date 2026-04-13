#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iValue[10001] = {};
int iDp[1001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> vecNums = {};
	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		int iSour;
		cin >> iSour;
		iValue[i] = iSour;
	}

	for (int i = 1; i <= iN; ++i)
	{
		iDp[i] = iValue[i];
	}

	for (int i = 2; i <= iN; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			iDp[i] = max(iDp[i], iDp[i - j] + iValue[j]);
		}
	}

	cout << iDp[iN];

	return 0;
}