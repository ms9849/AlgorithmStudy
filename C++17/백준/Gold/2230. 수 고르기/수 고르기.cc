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

	
	vector<long long> vecNums = {};
	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		long long iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	sort(vecNums.begin(), vecNums.end());

	int iLow = { 0 }, iHigh = { 0 };

	long long iResult = vecNums[iHigh] - vecNums[iLow];

	while (iLow <= iHigh && iHigh <= vecNums.size()-1)
	{
		int iDiff = vecNums[iHigh] - vecNums[iLow];

		if (iDiff > iM)
		{
			if (iResult > iDiff || iResult == 0)
				iResult = iDiff;

			iLow++;
		}
		else if (iDiff < iM)
		{
			iHigh++;
		}
		else
		{
			iResult = iM;
			break;
		}
	}

	cout << iResult;

	return 0;
}