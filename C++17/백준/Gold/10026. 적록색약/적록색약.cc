#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
그냥 BFS나 DFS 돌리면 될 것 같은데?..

1. 적록색약 (빨강과 초록을 동일 취급. 파랑과는 분리)
2. 일반인 (빨,파,초를 분리)

배열을 2번 순회하면서 조건에 따라 처리.
N이 최대 100이라.. 해봐야 1만칸
*/

char cBoard[101][101] = {};
int  iVisited[101][101] = {};

int iResultNorm = {};
int iResultRGB = {};

vector<pair<int, int>> vecDirs = {
	{ 1, 0 },
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 },
};

void DFS(int iCurY, int iCurX, char cTarget)
{
	iVisited[iCurY][iCurX] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int iNextY = iCurY + vecDirs[i].first;
		int iNextX = iCurX + vecDirs[i].second;

		if (!iVisited[iNextY][iNextX] && 
			cTarget == cBoard[iNextY][iNextX])
		{
			DFS(iNextY, iNextX, cTarget);
		}
	}
}

void DFS_RG(int iCurY, int iCurX, bool isRedGreen)
{
	iVisited[iCurY][iCurX] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int iNextY = iCurY + vecDirs[i].first;
		int iNextX = iCurX + vecDirs[i].second;

		if (!iVisited[iNextY][iNextX])
		{
			if (true == isRedGreen &&
			    (cBoard[iNextY][iNextX] == 'R' || cBoard[iNextY][iNextX] == 'G'))
				DFS_RG(iNextY, iNextX, true);

			else if(false == isRedGreen &&
				cBoard[iNextY][iNextX] == 'B')
				DFS_RG(iNextY, iNextX, false);
		}
	}
}

int main(void* pArg)
{
	int iSize;
	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cin >> cBoard[i][j];
		}
	}

	//일반인
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (!iVisited[i][j])
			{
				char cStart = cBoard[i][j];
				DFS(i, j, cStart);

				iResultNorm++;
			}
		}
	}

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			iVisited[i][j] = 0;

	//적록색약.
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (!iVisited[i][j])
			{
				char cStart = cBoard[i][j];

				if(cStart == 'R' || cStart == 'G')
					DFS_RG(i, j, true);
				else
					DFS_RG(i, j, false);
				iResultRGB++;
			}
		}
	}
	
	cout << iResultNorm << " " << iResultRGB << "\n";

	return 0;
}
