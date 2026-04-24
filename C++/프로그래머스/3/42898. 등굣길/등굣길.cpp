#include <string>
#include <vector>
#include <queue>
using namespace std;

int iX, iY;
int iGraph[101][101] = {};

int solution(int m, int n, vector<vector<int>> puddles) {
	
	int iY = n;
	int iX = m;

	int iMap[101][101] = {};
	int iDp[101][101] = {};

	iDp[1][1] = 1;

	for (auto& iter : puddles)
		iMap[iter[1]][iter[0]] = 1;

	for (int i = 1; i <= iY; ++i)
	{
		for (int j = 1; j <= iX; ++j)
		{
			if (i == 1 && j == 1)
				iDp[i][j] = 1;
			else
			{
				iDp[i][j] = (iDp[i - 1][j] + iDp[i][j - 1]) % 1000000007;

				if (iMap[i][j] == 1)
					iDp[i][j] = 0;
			}
		}
	}

	return iDp[iY][iX];
}
