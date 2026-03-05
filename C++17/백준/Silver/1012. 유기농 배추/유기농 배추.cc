#include <iostream>
#include <vector>

using namespace std;

int iArray[51][51] = { 0, };
int iVisited[51][51] = { 0, };
int iCount = 0;
int iM, iN;

vector<pair<int, int>> vecDirs = {};

void DFS(int iCurY, int iCurX)
{
	if (iVisited[iCurY][iCurX] == 0)
	{
		iVisited[iCurY][iCurX] = 1;

		for (int i = 0; i < 4; ++i)
		{
			if(iCurY + vecDirs[i].first >= 0 && iCurY + vecDirs[i].first < iN &&
				iCurX + vecDirs[i].second >= 0 && iCurX + vecDirs[i].second < iM &&
				iArray[iCurY + vecDirs[i].first][iCurX + vecDirs[i].second] == 1)
				DFS(iCurY + vecDirs[i].first, iCurX + vecDirs[i].second);
		}
	}
	else
		return;
}

int main(void* pArg)
{
	vecDirs.push_back(make_pair(1, 0));
	vecDirs.push_back(make_pair(-1, 0));
	vecDirs.push_back(make_pair(0, 1));
	vecDirs.push_back(make_pair(0, -1));
	//M이 가로, N이 세로.
	int iT, iK;

	cin >> iT;

	while (iT > 0)
	{
		iCount = 0;

		for (int i = 0; i <= iN; ++i)
		{
			for (int j = 0; j <= iM; ++j)
			{
				iArray[i][j] = { 0 };
				iVisited[i][j] = { 0 };
			}
		}

		cin >> iM >> iN >> iK;

		for (int i = 0; i < iK; ++i)
		{
			int iX, iY;
			cin >> iX >> iY;

			iArray[iY][iX] = 1;
		}

		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iM; ++j)
			{
				if (iArray[i][j] == 1 && 0 == iVisited[i][j])
				{
					DFS(i, j);
					iCount++;
				}
			}
		}

		cout << iCount << "\n";

		iT--;
	}

	return 0;
}