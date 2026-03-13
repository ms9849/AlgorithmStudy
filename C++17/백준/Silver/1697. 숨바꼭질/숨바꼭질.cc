#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dp[100001] = {};

int main(void* pArg)
{
	int iN, iK;

	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		dp[i] = iN - i;
	}


	for (int i = iN + 1; i <= iK; ++i)
	{
		if (i % 2 == 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		else
			dp[i] = min(min(dp[i - 1] + 1 , dp[(i - 1) / 2] + 2), dp[(i + 1) / 2] + 2);
	}

	cout << dp[iK] << "\n";

	return 0;
}