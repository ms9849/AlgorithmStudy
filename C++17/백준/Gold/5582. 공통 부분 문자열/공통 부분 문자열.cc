#include <iostream>
using namespace std;

int dp[4001][4001] = {};
int iMax = -1;
int iLastIdx;

//LCS는 기본적으로 iValue > iMax를 계속 통과할테니까?..
//계속 갱신하면.. 괜찮나?
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
			{
				iValue = dp[i + 1][j + 1] = dp[i][j] + 1;
				dp[i + 1][j + 1] = dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				iValue = dp[i + 1][j + 1] = 0;
			}
		
			if (iValue > iMax)
			{
				iMax = iValue;
				iLastIdx = i;
			}
		}
	}

	cout << iMax << "\n";



	return 0;
}