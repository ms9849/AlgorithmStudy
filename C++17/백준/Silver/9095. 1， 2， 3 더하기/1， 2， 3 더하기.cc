#include <iostream>

using namespace std;

int dp[12] = {0,};

int main(void* pArg)
{
	// 1 -> 1
	// 2 -> 2
	// 3 -> 3
	// 4 -> 7
	
	// 1 

	// 1 + 1
	// 2

	// 1 + 1 + 1
	// 2 + 1
	// 1 + 2
	// 3

	//1 + 1 + 1 + 1
	//1 + 1 + 2
	//1 + 2 + 1
	//2 + 1 + 1
	//2 + 2
	//1 + 3
	//3 + 1

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i-3];
	}

	int iN;
	cin >> iN;

	for (int i = 0; i < iN;++i)
	{
		int iIdx;
		cin >> iIdx;
		
		cout << dp[iIdx] << "\n";
	}

	return 0;
}