#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iValue[100001] = {};
int iNeedToRepair[100001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//..? 각 구간 별로 몇개의 신호등이 존재하는지 체크..


	int iN, iK, iB;
	int iSour;

	cin >> iN >> iK >> iB;

	for (int i = 0; i < iB; ++i)
	{
		cin >> iSour;

		//1이 고장난 신호등, 0이 멀쩡한 신호등.
		iValue[iSour] = 1;
	}

	int iMin = iK;

	for (int i = 1; i <= iN - iK + 1; ++i)
	{
		int iCnt = 0;

		for (int j = i; j < i + iK; ++j)
		{
			if (iValue[j] == 1)
				iCnt++;
		}

		if (iMin > iCnt)
			iMin = iCnt;
	}

	cout << iMin;

	return 0;
}