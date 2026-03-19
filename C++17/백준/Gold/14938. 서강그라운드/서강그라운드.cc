#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	int iGraph[101][101] = {};
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			iGraph[i][j] = 15000000;
		}
	}

	int iSour, iDest, iCost;
	int iN, iM, iR;
	vector<int> vecNums = {};

	cin >> iN >> iM >> iR;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iCost;
		vecNums.push_back(iCost);
	}

	for (int i = 0; i < iR; ++i)
	{
		cin >> iSour >> iDest >> iCost;

		iGraph[iSour][iDest] = iCost;
		iGraph[iDest][iSour] = iCost;
	}

	for (int k = 1; k <= iN; ++k)
	{
		for (int i = 1; i <= iN; ++i)
		{
			for (int j = 1; j <= iN; ++j)
			{
				//플로이드 워셜로 최단거리를 구한다.
				if (iGraph[i][j] > iGraph[i][k] + iGraph[k][j])
				{
					iGraph[i][j] = iGraph[i][k] + iGraph[k][j];
					iGraph[j][i] = iGraph[i][k] + iGraph[k][j];
				}
			}
		}
	}

	int iResult = 0;
	for (int i = 1; i <= iN; ++i)
	{
		int iCostSum = 0;

		for (int j = 1; j <= iN; ++j)
		{
			if (i ==j || iGraph[i][j] <= iM)
			{
				iCostSum += vecNums[j-1];
			}
		}

		if (iCostSum > iResult)
		{
			iResult = iCostSum;
		}
	}

	cout << iResult;


	return 0;
}