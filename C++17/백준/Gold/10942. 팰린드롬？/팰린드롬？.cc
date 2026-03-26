#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


int iDp[2001][2001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN, iE;
	int iNums[2001] = {};

	cin >> iN;
	
	for (int i = 1; i <= iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iNums[i] = iSour;
	}


	//미리 초기화.
	for (int i = 1; i <= iN; ++i)
	{
		iDp[i][i] = 1;
		if ((i <= (iN - 1)) && (iNums[i] == iNums[i + 1]))
			iDp[i][i + 1] = 1;
	}

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 0; j <= iN; ++j)
		{
			int iIndex = j;

			//3방향 체크.
			if (i + iIndex <= iN && 
				iDp[i + 1][i + iIndex - 1] == 1 && 
				iNums[i] == iNums[i+iIndex])
			{
				iDp[i][i + iIndex] = 1;
			}

			if (i - iIndex >= 1 && 
				iDp[i - iIndex + 1][i - 1] == 1 &&
				iNums[i-iIndex] == iNums[i])
			{
				iDp[i - iIndex][i] = 1;
			}

			if (i - iIndex >= 1 && 
				i + iIndex <= iN && 
				iDp[i - iIndex + 1][i + iIndex - 1] == 1 && 
				iNums[i - iIndex] == iNums[i + iIndex])
			{
				iDp[i-iIndex][i+iIndex] = 1;
			}
		}
	}

	cin >> iE;

	for (int i = 0; i < iE; ++i)
	{
		int iStart, iEnd;
		cin >> iStart >> iEnd;

		if (iDp[iStart][iEnd] == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}