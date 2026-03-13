#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

long long dp[105] = {};

int main(void* pArg)
{
	int iN;
	cin >> iN;


	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}


	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		cout << dp[iSour] << "\n";
	}

	return 0;
}