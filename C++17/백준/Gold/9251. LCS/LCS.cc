#include <iostream>
using namespace std;

int dp[1001][1001] = {0, };
int iMax = -1;

int main(void* pArg)
{
	string strSour, strDest;

	cin >> strSour >> strDest;

	for (int i = 0; i < strSour.size(); ++i)
	{
		for (int j = 0; j < strDest.size(); ++j)
		{
			int iValue = {};

			if (strSour[i] == strDest[j])
				iValue = dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				iValue = dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		
			if (iValue > iMax)
				iMax = iValue;
		}
	}

	cout << iMax << "\n";

	return 0;
}