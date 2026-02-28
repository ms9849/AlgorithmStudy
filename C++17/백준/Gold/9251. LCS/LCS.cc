#include <iostream>
using namespace std;

int dp[1002][1002] = {};
int iMax = 0;

int main(void* pArg)
{
	string strSour, strDest;

	cin >> strSour >> strDest;

	for (int i = 0; i < strSour.size(); ++i)
	{
		for (int j = 0; j < strDest.size(); ++j)
		{
			if (strSour[i] == strDest[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			
				if (dp[i + 1][j + 1] > iMax)
					iMax = dp[i + 1][j + 1];
			}
			else
				dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}


	cout << iMax << "\n";

	return 0;
}