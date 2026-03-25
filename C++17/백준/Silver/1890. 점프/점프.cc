#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	int iN;
	long long iMap[101][101] = {};
	long long iDp[101][101] = {};

	cin >> iN;

	for (int i = 1; i <= iN; ++i)
		for (int j = 1; j <= iN; ++j)
			cin >> iMap[i][j];

	iDp[1][1] = 1;

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			int iCount = iMap[i][j];
			
			if (iCount != 0)
			{
				//점프할수있는 칸에 ++ 
				if (i + iCount <= iN)
					iDp[i + iCount][j] += iDp[i][j];

				if (j + iCount <= iN)
					iDp[i][j + iCount] += iDp[i][j];
			}
		}
	}

	cout << iDp[iN][iN];

	return 0;
}