#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
플로이드 워셜?

BFS나 DFS도 괜찮을 것 같긴한데..
Visited 체크 해서 방문이 안됐으면 X 처리.
치즈가 한번 녹을때마다 외부 공기 유입됐는지 체크 해줘야 하는데?..

내부 공간은 2로 처리.

녹을때마다 탐색 -> 외부 공간이 아니게 된 곳은 0으로 처리. 
진짜 visited만 체크하는거라.. 그렇게 무겁진 않을 것 같긴 하다.
백트래킹도 괜찮나 싶긴한데 이건 별로일듯?

그럼.. 녹는건 최대 몇번이지? 99x99 니까.. 1만번은 안됨. BFS 1만번? 1만개의 정점이니까.. 
괜찮을듯?
*/

int iSizeX, iSizeY;
int iBoard[101][101] = {};
int iResult = 0;

int main(void* pArg)
{
	vector<pair<int, int>> vecDirs = {
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1}
	};
	queue<pair<int, int>> q = {};

	cin >> iSizeY >> iSizeX;

	for (int i = 0; i < iSizeY; ++i)
	{
		for (int j = 0; j < iSizeX; ++j)
		{
			cin >> iBoard[i][j];
		}
	}

	while (1)
	{
		int iVisited[101][101] = {};
		q.push(make_pair(0, 0));

		while (!q.empty())
		{
			pair<int, int> CurNode = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int iNextY = CurNode.first + vecDirs[i].first;
				int iNextX = CurNode.second + vecDirs[i].second;

				if ((iVisited[iNextY][iNextX] == 0) && 
					(iBoard[iNextY][iNextX] == 0) &&
					(iNextY >= 0 && iNextY < iSizeY && iNextX >= 0 && iNextX < iSizeX))
				{
					iVisited[iNextY][iNextX] = 1;
					q.push(make_pair(iNextY, iNextX)); 
				}
			}
		}


		int iCheeseCount = 0;
		//내부 공기 체크
		for (int i = 0; i < iSizeY; ++i)
		{
			for (int j = 0; j < iSizeX; ++j)
			{
				int iCount = 0;
				for (int k = 0; k < 4; ++k)
				{
					int iNextY = i + vecDirs[k].first;
					int iNextX = j + vecDirs[k].second;

					if (iBoard[i][j] == 1)
					{
						iCheeseCount++;

						if ((iVisited[iNextY][iNextX] == 1) &&
							(iBoard[iNextY][iNextX] == 0) &&
							(iNextY >= 0 && iNextY < iSizeY && iNextX >= 0 && iNextX < iSizeX))
						{
							iCount++;
						}
					}
				}

				if (iCount >= 2)
					iBoard[i][j] = 0;
			}
		}

		if (iCheeseCount == 0)
			break;

		iResult++;
	}

	cout << iResult;
	return 0;
}