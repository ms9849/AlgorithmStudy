#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iM,iN;

int iMap[1001][1001] = {};

vector<pair<int, int>> vecDirs = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool Check_Secure(int iY, int iX)
{
	if (!(iY >= 0 && iY < iM &&
		iX >= 0 && iX < iN))
	{
		return false;
	}

	return true;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<pair<int, int>> iVisitNodes = {};

	cin >> iN >> iM;

	for (int i = 0; i < iM; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> iMap[i][j];

			if (iMap[i][j] == 1)
				iVisitNodes.push(make_pair(i, j));
		}
	}

	while (!iVisitNodes.empty())
	{
		pair<int, int> iCurNode = iVisitNodes.front();
		iVisitNodes.pop();


		for (int i = 0; i < 4; ++i)
		{
			int iNextY = iCurNode.first + vecDirs[i].first;
			int iNextX = iCurNode.second + vecDirs[i].second;
			if (Check_Secure(iNextY, iNextX) && iMap[iNextY][iNextX] == 0)
			{
				iMap[iNextY][iNextX] = iMap[iCurNode.first][iCurNode.second] + 1;
				iVisitNodes.push(make_pair(iNextY, iNextX));
			}
		}
	}

	int iResult = { 1 };

	for (int i=0; i<iM; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (iMap[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}

			if (iMap[i][j] > iResult)
				iResult = iMap[i][j];
		}
	}

	cout << iResult - 1 << "\n";

	return 0;
}