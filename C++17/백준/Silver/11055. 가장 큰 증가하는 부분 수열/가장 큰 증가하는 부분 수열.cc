#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iArray[1001] = {};
int iDp[1001] = {};

int main(void* pArg)
{
	int iN;
	int iResult = { 0 };

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iArray[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		iDp[i] = iArray[i];
		for (int j = 0; j < i; ++j)
		{
			if (iArray[i] > iArray[j])
			{
				iDp[i] = max(iDp[i], iDp[j] + iArray[i]);
			}
		}

		iResult = max(iResult, iDp[i]);
	}

	cout << iResult;

	return 0;
}