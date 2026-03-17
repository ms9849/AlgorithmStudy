#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	int iT;

	cin >> iT;

	while (iT > 0)
	{
		int iBoard[2][100001] = {};
		int dp[2][100001] = {};

		int iN;
		cin >> iN;

		for (int j = 0; j <= 1; ++j)
		{
			for (int i = 0; i < iN; ++i)
			{
				cin >> iBoard[j][i];
			}
		}

		dp[0][0] = iBoard[0][0];
		dp[1][0] = iBoard[1][0];
		dp[0][1] = dp[1][0] + iBoard[0][1];
		dp[1][1] = dp[0][0] + iBoard[1][1];

		for (int i = 2; i <= iN- 1; ++i)
		{
			dp[0][i] = max(max(dp[1][i -1], dp[0][i-2]), dp[1][i-2]) + iBoard[0][i];
			dp[1][i] = max(max(dp[0][i -1], dp[0][i-2]), dp[1][i-2]) + iBoard[1][i];
		}

		cout << max(dp[0][iN-1], dp[1][iN-1]) << "\n";

		iT--;
	}
	return 0;
}