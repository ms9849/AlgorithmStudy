#include <iostream>
using namespace std;

long long dp[1001][10] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iN;
	cin >> iN;

	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= iN; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[i][j] += (dp[i - 1][k]) % 10007;
			}
		}
	}


	long long iSum = 0;
	for (int i = 0; i < 10; ++i)
	{
		iSum += dp[iN][i] % 10007;
	}

	cout << iSum % 10007;

	return 0;
}