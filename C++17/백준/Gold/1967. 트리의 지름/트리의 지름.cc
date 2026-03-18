#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vecEdges[10001] = {};

int iVisited[10001] = {};
int iDist[10001] = {};

void DFS(int iStart)
{
	for (auto& iter : vecEdges[iStart])
	{
		if (!iVisited[iter.first])
		{
			iDist[iter.first] = iDist[iStart] + iter.second;
			iVisited[iter.first] = true;
			
			DFS(iter.first);

			iVisited[iter.first] = false;
		}
	}
}

int main(void* pArg)
{
	int iN;

	cin >> iN;

	for (int i = 0; i < iN - 1; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;

		vecEdges[iSour].push_back(make_pair(iDest, iCost));
		vecEdges[iDest].push_back(make_pair(iSour, iCost));
	}

	iVisited[1] = 1;
	DFS(1);

	int iMaxValue = -1;
	int iNextNode = -1;

	for (int i = 1; i <= iN; ++i)
	{
		if (iDist[i] > iMaxValue)
		{
			iMaxValue = iDist[i];
			iNextNode = i;
		}

		iVisited[i] = 0;
		iDist[i] = 0;
	}

	iVisited[iNextNode] = 1;
	DFS(iNextNode);

	iMaxValue = -1;
	int iResultNode = {};

	for (int i = 1; i <= iN; ++i)
	{
		if (iDist[i] > iMaxValue)
		{
			iMaxValue = iDist[i];
			iResultNode = i;
		}
	}

	cout << iMaxValue;

	return 0;
}