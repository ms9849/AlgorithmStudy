#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iSizeX, iSizeY;
int iStartX, iStartY;
int iBoard[601][601] = {};
int iVisited[601][601] = {};

queue<pair<int, int>> q = {};

vector<pair<int, int>> vecDirs = {
	{0,1},
	{1,0},
	{-1,0},
	{0,-1}
};

int main(void* pArg)
{
	cin >> iSizeY >> iSizeX;

	for (int i = 0; i < iSizeY; ++i)
	{
		string strMap;
		cin >> strMap;

		for (int j = 0; j < iSizeX; ++j)
		{
			char cInfo = strMap[j];

			switch (cInfo)
			{
			case 'O':
				iBoard[i][j] = 0;
				break;
			case 'I':
				iStartY = i;
				iStartX = j;
				break;
			case 'P':
				iBoard[i][j] = 2;
				break;
			case 'X':
				iBoard[i][j] = 1;
				break;
			default:
				break;
			}
		}
	}

	int iCount = 0;
	q.push(make_pair(iStartY, iStartX));
	iVisited[iStartY][iStartX] = 1;

	while (!q.empty())
	{
		int iCurY = q.front().first;
		int iCurX = q.front().second;

		q.pop();

		for(int i=0; i<4; ++i)
		{
			//인덱스 안벗어나고,
			//방문한적 없고,
			//보드가 막힌 곳이 아니라면.
			if (iCurY + vecDirs[i].first >= 0 &&
				iCurY + vecDirs[i].first < iSizeY &&
				iCurX + vecDirs[i].second >= 0 &&
				iCurX + vecDirs[i].second < iSizeX &&
				iVisited[iCurY + vecDirs[i].first][iCurX + vecDirs[i].second] == 0 &&
				iBoard[iCurY + vecDirs[i].first][iCurX + vecDirs[i].second] != 1)
			{
				iVisited[iCurY + vecDirs[i].first][iCurX + vecDirs[i].second] = 1;
				q.push(make_pair(iCurY + vecDirs[i].first, iCurX + vecDirs[i].second));

				if (iBoard[iCurY + vecDirs[i].first][iCurX + vecDirs[i].second])
				{
					iCount++;
				}
			}
		}
	}

	if (iCount == 0)
		cout << "TT";
	else
		cout << iCount;

	return 0;
}