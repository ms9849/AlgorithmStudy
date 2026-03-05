#include <iostream>
#include <queue>
using namespace std;

int iGraph[1001][1001] = { 0, };
int iVisited[1001][1001] = { 0, };
vector<pair<int, int>> vecDirs = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iN, iM;

	int iStartX, iStartY;
	queue <pair<int,int> > VisitNodes;
	
	for (int i = 0; i < 1001;++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			iVisited[i][j] = 4000;
		}
	}

	vecDirs.push_back(make_pair(0, 1));
	vecDirs.push_back(make_pair(1, 0));
	vecDirs.push_back(make_pair(-1, 0));
	vecDirs.push_back(make_pair(0, -1));

	cin >> iN >> iM;;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iNum;

			cin >> iNum;

			iGraph[i][j] = iNum;

			if (iNum == 2)
			{
				iStartY = i;
				iStartX = j;
			}
		}
	}

	VisitNodes.push(make_pair(iStartY, iStartX));
	iVisited[iStartY][iStartX] = 0;

	while (!VisitNodes.empty())
	{
		int iCurNodeY = VisitNodes.front().first;
		int iCurNodeX = VisitNodes.front().second;

		VisitNodes.pop();

		for (auto& iter : vecDirs)
		{
			if (iCurNodeY + iter.first >= 0 && iCurNodeY + iter.first < iN &&
				iCurNodeX + iter.second >= 0 && iCurNodeX + iter.second < iM)
			{
				if ((iVisited[iCurNodeY + iter.first][iCurNodeX + iter.second] > iVisited[iCurNodeY][iCurNodeX] + 1) &&
					iGraph[iCurNodeY + iter.first][iCurNodeX + iter.second] == 1)
				{
					VisitNodes.push(make_pair(iCurNodeY + iter.first, iCurNodeX + iter.second));
					iVisited[iCurNodeY + iter.first][iCurNodeX + iter.second] = 
						iVisited[iCurNodeY][iCurNodeX] + 1;
				}
			}
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (iGraph[i][j] == 0)
				cout << "0 ";
			else if (iGraph[i][j] != 0 && iVisited[i][j] == 4000)
				cout << "-1 ";
			else
				cout << iVisited[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}