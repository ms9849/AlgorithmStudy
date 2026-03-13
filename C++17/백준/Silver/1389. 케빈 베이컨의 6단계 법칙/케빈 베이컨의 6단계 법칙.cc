#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iGraph[101][101] = {};
int iResult[101] = {0,};
int main(void* pArg)
{
	int iN, iM;

	cin >> iN >> iM;

	for (int i = 0; i < iM;++i)
	{
		int iSour, iDest;
		cin >> iSour >> iDest;

		iGraph[iSour][iDest] = 1;
		iGraph[iDest][iSour] = 1;
	}

	for (int i = 1; i <= iN; ++i)
	{
		int iVisited[101] = {};
		int iStart = i;

		iVisited[iStart] = 1;

		queue<int> q = {};
		q.push(i);

		while (!q.empty())
		{
			int iCurNode = q.front();
			q.pop();

			for (int j = 1; j <= iN; ++j)
			{
				if (j != iCurNode && iVisited[j] == 0 &&
					iGraph[iCurNode][j] == 1)
				{
					iVisited[j] = iVisited[iCurNode] + 1;
					q.push(j);
				}
			}
		}

		for (int j = 1; j <= iN; ++j)
		{
			if(iVisited[j] != 0)
				iResult[i] += (iVisited[j] -1);
		}
	}

	int iMin = 987654321;
	int iIdx = -1;
	for (int i = iN; i >= 1; --i)
	{
		if (iMin >= iResult[i])
		{
			iMin = iResult[i];
			iIdx = i;
		}
	}

	cout << iIdx << "\n";

	return 0;
}