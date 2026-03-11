#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iCost[1000][3] = {};
int dp[1000][3] = {};

int main(void* pArg)
{
	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> iCost[i][j];
		}
	}

	int iSum = 0;

	dp[0][0] = iCost[0][0];
	dp[0][1] = iCost[0][1];
	dp[0][2] = iCost[0][2];

	for (int i = 1; i < 1000; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
				dp[i][j] = min(dp[i - 1][1] + iCost[i][0], dp[i - 1][2] + iCost[i][0]);
			else if (j == 1)
				dp[i][j] = min(dp[i - 1][0] + iCost[i][1], dp[i - 1][2] + iCost[i][1]);
			else if (j == 2)
				dp[i][j] = min(dp[i - 1][0] + iCost[i][2], dp[i - 1][1] + iCost[i][2]);
		}
	}

	cout << min(min(dp[iN - 1][0], dp[iN - 1][1]), dp[iN - 1][2]);

	return 0;
}