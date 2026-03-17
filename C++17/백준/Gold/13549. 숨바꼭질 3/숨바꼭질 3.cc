#include <iostream>

using namespace std;

int dp[100001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN, iK;

	cin >> iN >> iK;

	// 동생 위치가 수빈이보다 작을떈 고려하지 않음 
	if (iK <= iN)
	{
		cout << iN - iK;
		return 0;
	}

	for (int i = 0; i <= iN; ++i)
	{
		dp[i] = iN - i;
	}

	for (int i = iN + 1; i <= 100000; ++i)
	{
		int iMin = 100001;
		iMin = min(dp[i - 1] + 1, iMin);

		if (i % 2 == 0)
		{
			iMin = min(iMin, dp[i / 2]);
		}
		else if (i % 2 == 1)
		{
			iMin = min(min(iMin, dp[(i - 1) / 2] + 1), dp[(i+1)/2] + 1);
		}

		dp[i] = iMin;
	}

	cout << dp[iK];

	return 0;
}