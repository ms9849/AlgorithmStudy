#include <iostream>
using namespace std;

int iV, iE;
int iVisited[1001] = { 0, };
int iGraph[1001][1001] = { 0, };
int iCount = 0;

void DFS(int iStartNode)
{
	iVisited[iStartNode] = 1;

	for (int i = 1; i <= iV; ++i)
	{
		if ((iGraph[iStartNode][i] == 1 || iGraph[i][iStartNode] == 1) &&
			iVisited[i] == 0)
			DFS(i);
	}
}

int main(void* pArg)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> iV >> iE;

	for (int i = 0; i < iE; ++i)
	{
		int iSour, iDest;
		cin >> iSour >> iDest;

		iGraph[iSour][iDest] = 1;
		iGraph[iDest][iSour] = 1;
	}

	for (int i = 1; i <= iV; ++i)
	{
		if (iVisited[i] == 0)
		{
			DFS(i);
			iCount++;
		}
	}

	cout << iCount;

	return 0;
}