#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int iSize = {};
pair<int, int> CurPos = {};
vector<pair<int, int>> vecDirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

int iArray[21][21] = {};
int iCurSize = 2;
int iEatSize = 0;
int iResult = 0;

int main(void* pArg)
{
	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cin >> iArray[i][j];
		
			if (iArray[i][j] == 9)
			{
				CurPos.first = i;
				CurPos.second = j;
			}
		}
	}

	while (1)
	{
		int iMinDist = 401;
		pair<int, int> TargetPos = {-1,-1};
		queue<pair<pair<int, int>,int>> q = {};

		q.push(make_pair(make_pair(CurPos.first, CurPos.second), 0));

		int iVisited[21][21] = {};
		iVisited[CurPos.first][CurPos.second] = 1;

		while (!q.empty())
		{
			pair<pair<int, int>,int> CurNode = q.front();
			q.pop();

			if ((iArray[CurNode.first.first][CurNode.first.second] != 9) &&
				(iArray[CurNode.first.first][CurNode.first.second] != 0) &&
				iCurSize > iArray[CurNode.first.first][CurNode.first.second] && 
				CurNode.second <= iMinDist)
			{
				iMinDist = CurNode.second;

				// 첫 갱신. 제한없이 해준다.
				if ((TargetPos.first == -1) && (TargetPos.second == -1))
				{
					TargetPos = CurNode.first;
				}
				// 만약 y가 더작다면 갱신.
				else if ((TargetPos.first > CurNode.first.first))
				{
					TargetPos = CurNode.first;
				}
				// y는 같은데 x가 작다면 갱신. (높이 따지고, 왼쪽부터.)
				else if((TargetPos.first == CurNode.first.first))
				{
					if (TargetPos.second > CurNode.first.second)
					{
						TargetPos = CurNode.first;
					}
				}
			}

			for (int i = 0; i < 4; ++i)
			{
				int iNextY = CurNode.first.first + vecDirs[i].first;
				int iNextX = CurNode.first.second + vecDirs[i].second;

				//같아도  통과할 수 있음.
				if (iCurSize >= iArray[iNextY][iNextX] &&
					iVisited[iNextY][iNextX] == 0 && 
					(iNextY >= 0 && iNextY < iSize && iNextX >= 0 && iNextX < iSize))
				{
					iVisited[iNextY][iNextX] = 1;
					q.push(make_pair(make_pair(iNextY, iNextX), CurNode.second + 1));
				}
			}
		}

		if (TargetPos.first == -1 && TargetPos.second == -1)
			break;

		iArray[CurPos.first][CurPos.second] = 0;
		CurPos = TargetPos;
		iArray[CurPos.first][CurPos.second] = 9;
		iResult += iMinDist;

		iEatSize++;

		if (iEatSize == iCurSize)
		{
			iCurSize++;
			iEatSize = 0;
		}
	}

	cout << iResult;

	return 0;
}