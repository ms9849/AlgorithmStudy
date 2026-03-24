#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iDp[1001] = {};
int iMaxLength = {};

int main(void* pArg)
{
	vector<int> vecNums = {};
	int iN; 

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	iDp[1] = 1;
	iMaxLength = iDp[1];

	for (int i = 2; i <= iN; ++i)
	{
		iDp[i] = 1;

		for (int j = 1; j < i; ++j)
		{
			if (vecNums[i - 1] > vecNums[j - 1])
			{
				iDp[i] = max(iDp[i], iDp[j] + 1);
				iMaxLength = max(iMaxLength, iDp[i]);
			}
		}
	}

	cout << iMaxLength << "\n";

	return 0;
}