#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
분류상으론 그리디..

회의 시간이 가장 빨리 끝나는 녀석들부터 골라야
더 많은 회의를 고를 수 있게 된다.

*/
int main(void* pArg)
{
	vector<pair<int, int>> vecTimes = {};
	int iStart, iEnd;
	int iN;

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iStart >> iEnd;

		vecTimes.push_back(make_pair(iStart, iEnd));
	}

	sort(vecTimes.begin(), vecTimes.end(), [](pair<int,int> iLhs, pair<int,int> iRhs)->bool {
		
		if (iLhs.second == iRhs.second)
			return iLhs.first < iRhs.first;

		return iLhs.second < iRhs.second;
	});


	int iCount = 1;
	int iEndTime = vecTimes.begin()->second;

	for (int i = 1; i < iN; ++i)
	{
		if (vecTimes[i].first >= iEndTime)
		{
			iCount++;
			iEndTime = vecTimes[i].second;
		}
	}

	cout << iCount;

	return 0;
}