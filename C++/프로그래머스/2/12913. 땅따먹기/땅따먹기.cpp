#include <iostream>
#include <vector>
using namespace std;

int iDp[100001][5] = {};
//열당 10만번. DP로 풀이 가능
int solution(vector<vector<int>> land)
{
	int iRowSize = land.size();

	for (int i = 0; i < 4; ++i)
	{
		iDp[0][i] = land[0][i];
	}

	for (int i = 1; i < iRowSize; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				if (j != k)
				{
					iDp[i][j] = max(iDp[i - 1][k] + land[i][j], iDp[i][j]);
				}
			}
		}
	}

	int iMax = -1;
	for (int i = 0; i < 4; ++i)
	{
		iMax = max(iMax, iDp[iRowSize - 1][i]);
	}

	return iMax;
}