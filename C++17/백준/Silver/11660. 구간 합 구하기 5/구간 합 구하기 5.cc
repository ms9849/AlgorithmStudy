#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iBoard[1025][1025] = {};
int iDp[1025][1025] = {};

int main(void* pArg)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);

	int iN, iM;

	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
		for (int j = 1; j <= iN; ++j)
			cin >> iBoard[i][j];

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			iDp[i][j] = iDp[i][j - 1] + iDp[i - 1][j] - iDp[i - 1][j - 1] + iBoard[i][j];
		}
	}


	while (iM > 0)
	{
		int iStartX, iStartY, iEndX, iEndY;
		cin >> iStartX >> iStartY >> iEndX >> iEndY;


		cout << iDp[iEndX][iEndY] 
			- iDp[iStartX-1][iEndY] - iDp[iEndX][iStartY-1] 
			+ iDp[iStartX-1][iStartY-1] << "\n";

		iM--;
	}

	return 0;
}