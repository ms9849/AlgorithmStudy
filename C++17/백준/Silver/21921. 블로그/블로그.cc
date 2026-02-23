#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iVisited[250001] = { 0, };
int iVisitedSumArray[250001] = { 0, };
int iN, iX;

int main(void* pArg)
{
	ios::sync_with_stdio();
	cin.tie(NULL);

	cin >> iN >> iX;
	int iVisitedSum = { 0 };
	int iVisitedIdx = { 0 };

	for (int i = 1; i <= iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iVisited[i] = iSour;

		iVisitedIdx++;
		iVisitedSum += iSour;


		if (iVisitedIdx >= iX)
		{
			iVisitedSumArray[i - iX + 1] = iVisitedSum;
			iVisitedSum -= iVisited[i - iX + 1];
		}
	}

	int iMaxValue = { -1 };
	int iMaxCnt = { 0 };

	for (int i = 1; i <= iN; ++i)
	{
		if (iMaxValue < iVisitedSumArray[i])
		{
			iMaxCnt = 0;
			iMaxValue = iVisitedSumArray[i];
			iMaxCnt++;
		}
		
		else if (iMaxValue == iVisitedSumArray[i])
		{
			iMaxCnt++;
		}
	}

	//출력 파트

	if (iMaxValue == 0)
	{
		cout << "SAD";
		return 0;
	}

	cout << iMaxValue << "\n";
	cout << iMaxCnt;

	return 0;
}