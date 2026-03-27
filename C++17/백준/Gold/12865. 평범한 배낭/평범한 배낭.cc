#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iW[101] = {};
int iV[101] = {};
int dp[101][100001];

/*
i번쨰 물건까지 고려했을떄,
무게 k 이하에서 얻을 수 있는 최대 행복의 가치를 기록해야 한다.

-> 이게 냅색의 기본이라는데..
*/

int main(void* pArg)
{
	int iN, iK;

	cin >> iN >> iK;

	for (int i = 1; i <= iN; ++i)
		cin >> iW[i] >> iV[i];

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iK; ++j)
		{
			dp[i][j] = dp[i - 1][j];

			if (j >= iW[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - iW[i]] + iV[i]);
			}
		}
	}

	cout << dp[iN][iK];
	return 0;
cout <<"1";
	return 0;
}