#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

char cBoard[21][21] = {};
int iVisited[26] = {};
int iResult = { 1 };
int iSizeY, iSizeX;

vector<pair<int, int>> vecDirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

void DFS(int iCurY, int iCurX, int iCount)
{
	if (iResult < iCount)
		iResult = iCount;

	for (int i = 0; i < 4; ++i)
	{
		int iNextY = iCurY + vecDirs[i].first;
		int iNextX = iCurX + vecDirs[i].second;

		if (iVisited[cBoard[iNextY][iNextX] - 'A'] == 0 &&
			iNextY >= 0 &&
			iNextY < iSizeY &&
			iNextX >= 0 &&
			iNextX < iSizeX)
		{
			iVisited[cBoard[iNextY][iNextX] - 'A'] = 1;
			DFS(iNextY, iNextX, iCount + 1);
			iVisited[cBoard[iNextY][iNextX] - 'A'] = 0;
		}
	}
}

int main(void* pArg)
{
	cin >> iSizeY >> iSizeX;

	for (int i = 0; i < iSizeY; ++i)
	{
		string strMap = {};
		cin >> strMap;
		for (int j = 0; j < iSizeX; ++j)
		{
			cBoard[i][j] = strMap[j];
		}
	}

	iVisited[cBoard[0][0] - 'A'] = 1;
	DFS(0, 0, 1);

	cout << iResult << "\n";

	return 0;
}