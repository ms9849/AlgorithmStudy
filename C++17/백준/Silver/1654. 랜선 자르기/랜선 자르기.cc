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

	int iK, iN;
	long long iLow{1}, iHigh{};

	vector<long long> vecNums = {};

	cin >> iK >> iN;

	for (int i = 0; i < iK; ++i)
	{
		long long iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	
		if (iSour > iHigh)
			iHigh = iSour;
	}
	
	int iMaxLen = 0;

	while (iLow <= iHigh)
	{
		long long iMid = (iLow + iHigh) / 2;
		int iCount = 0;

		for (int i = 0; i < iK; ++i)
			iCount += vecNums[i] / iMid;
	
		//너무 많이 나오면, 랜선 길이 늘려야지
		if (iCount >= iN)
		{
			iLow = iMid + 1;

			if (iMaxLen < iMid)
				iMaxLen = iMid;
		}
		//너무 적게 나오면 랜선 길이 줄여잇.
		else
			iHigh = iMid - 1; 
	}

	cout << iMaxLen;

	return 0;
}