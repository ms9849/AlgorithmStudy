#include <iostream>
using namespace std;

int dp[41][2] = {0};
int main(void* pArg)
{
	int iN;

	cin >> iN;

	dp[1][1] = 1;
	dp[0][0] = 1;

	for (int i = 2; i <= 40; ++i)
	{
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
	}

	for (int i = 0; i < iN; ++i)
	{
		int iIdx;
		cin >> iIdx;
		cout << dp[iIdx][0] << " " << dp[iIdx][1] << "\n";
	}

	return 0;
}