#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int iGraph[101][101] = { 0, };
int iCost[101][101] = { 0, };

vector<pair<int, int>> vecDirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

int main(void* pArg)
{
	queue<pair<int,int>> q;
	int iN, iM;
	cin >> iN >> iM;

	iCost[1][1] = 1;


	for (int i = 1; i <= iN; ++i)
	{
		string strSour;
		cin >> strSour;

		for (int j = 1; j <= iM; ++j)
		{

			iGraph[i][j] = strSour[j-1] - '0';
		}
	}
	
	q.push(make_pair(1,1));

	while (!q.empty())
	{
		pair<int, int> CurNode = q.front();

		q.pop();

		if (CurNode.first == iN && CurNode.second == iM)
		{
			cout << iCost[iN][iM];
			break;
		}
		else if (iCost[iN][iM] != 0 && iCost[iN][iM] != 1)
		{
			continue;
		}


		for (int i = 0; i < 4; ++i)
		{
			if (iGraph[CurNode.first + vecDirs[i].first][CurNode.second + vecDirs[i].second] == 1 &&
				iCost[CurNode.first + vecDirs[i].first][CurNode.second + vecDirs[i].second] == 0)
			{
				q.push(make_pair(CurNode.first + vecDirs[i].first, CurNode.second + vecDirs[i].second));
				iCost[CurNode.first + vecDirs[i].first][CurNode.second + vecDirs[i].second] = iCost[CurNode.first][CurNode.second] + 1;
			}
		}
	}

	return 0;
}