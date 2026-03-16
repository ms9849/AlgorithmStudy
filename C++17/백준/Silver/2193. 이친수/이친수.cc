#include <iostream>

using namespace std;

long long dp[91][2] = {};

int main(void* pArg)
{
	long long iN;
	cin >> iN;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= iN; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}


	long long iSum = dp[iN][0] + dp[iN][1];

	cout << iSum << "\n"; 

	return 0;
}