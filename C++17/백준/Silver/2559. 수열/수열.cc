#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iValue[100001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN{}, iK{}, iCnt{};

	int iCount = 0;
	int iSum = 0;
	int iMax = -300000000;

	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iValue[i] = iSour;

		// 체크.
		iCount++;
		iSum += iSour;

		if (iCount > iK)
		{
			iSum -= iValue[i - iK];
			iCount--;
		}

		if (iCount == iK)
		{
			if (iMax < iSum)
				iMax = iSum;
		}
	}

	cout << iMax << "\n";

	return 0;
}