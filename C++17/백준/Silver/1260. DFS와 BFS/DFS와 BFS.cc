#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iGraph[1001][1001] = {};
int iCurNode = {};
int iVisited[1001] = {};

void DFS(int iCurNode)
{
	cout << iCurNode << " ";

	for (int i = 1; i <= 1000; ++i)
	{
		if (iVisited[i] == 0 && 
			iGraph[iCurNode][i] == 1)
		{
			iVisited[i] = true;
			DFS(i);
		}
	}
}


int main(void* pArg)
{
	int iN, iM, iStart;

	cin >> iN >> iM >> iStart;

	for (int i = 0; i < iM; ++i)
	{
		int iSour, iDest;
		
		cin >> iSour >> iDest;
		iGraph[iSour][iDest] = 1;
		iGraph[iDest][iSour] = 1;
	}

	//dfs
	iVisited[iStart] = 1;
	DFS(iStart);

	for (int i = 0; i <= 1000; ++i)
		iVisited[i] = 0;
	cout << "\n";

	//bfs
	queue<int> iReserved = {};

	iReserved.push(iStart);
	while (!iReserved.empty())
	{
		int iCurNode = iReserved.front();
		iReserved.pop();

		if (iVisited[iCurNode] == 0)
		{
			cout << iCurNode << " ";
			iVisited[iCurNode] = 1;
		}
		else
			continue;

		for (int i = 1; i <= 1000; ++i)
		{
			if (iVisited[i] == 0 &&
				iGraph[iCurNode][i] == 1)
			{
				iReserved.push(i);
			}
		}
	}


	return 0;
}
