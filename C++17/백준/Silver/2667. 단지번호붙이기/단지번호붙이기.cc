#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int iN;
int iMap[26][26] = {};
int iVisited[26][26] = {};

vector<pair<int, int>> vecDirs = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

vector<int> vecNums = {};

bool Check_Secure(int iY, int iX)
{
	if (iY >= 0 && iY < iN && iX >= 0 && iX < iN)
		return true;

	else
		return false;
}

int main(void* pArg)
{

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < iN; ++j)
		{
			iMap[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (iVisited[i][j] == 0 && iMap[i][j] == 1)
			{
				queue<pair<int,int>> q = {};
				q.push(make_pair(i, j));

				int iCount = 0;

				while (!q.empty())
				{
					pair<int, int> CurNode = q.front();
					q.pop();

					iCount++;
					iVisited[CurNode.first][CurNode.second] = 1;


					for (int i = 0; i < 4; ++i)
					{
						int iNextY = CurNode.first + vecDirs[i].first;
						int iNextX = CurNode.second + vecDirs[i].second;
					
						if (Check_Secure(iNextY, iNextX) &&
							iVisited[iNextY][iNextX] == 0 &&
							iMap[iNextY][iNextX] == 1)
						{
							q.push(make_pair(iNextY, iNextX));
							iVisited[iNextY][iNextX] = 1;
						}
					}
				}

				vecNums.push_back(iCount);
			}
		}
	}

	sort(vecNums.begin(), vecNums.end());

	
	cout << vecNums.size() << "\n";

	for (auto& iter : vecNums)
		cout << iter << "\n";



	return 0;
}