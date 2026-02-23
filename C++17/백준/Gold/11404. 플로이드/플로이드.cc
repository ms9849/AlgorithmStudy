#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN{};
int iE{};

long long iGraph[101][101] = {0,};

void Find_Path()
{
	for (int i = 1; i <= iN; ++i) // 거쳐가는 정점
	{
		for (int j = 1; j <= iN; ++j) // 출발 정점
		{
			for (int k = 1; k <= iN; ++k) // 도착 정점
			{
				if (j == k || i == k || i == j)
					continue;

				if (iGraph[j][k] > iGraph[j][i] + iGraph[i][k])
					iGraph[j][k] = iGraph[j][i] + iGraph[i][k];
			}
		}
	}
}

int main(void* pArg)
{
	cin >> iN;
	cin >> iE;

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			if (i == j) continue;

			iGraph[i][j] = 98765432;
		}
	}

	for (int i = 0; i < iE; ++i)
	{
		int iSour, iDest;
		long long iCost;

		cin >> iSour >> iDest >> iCost;

		iGraph[iSour][iDest] = min(iGraph[iSour][iDest], iCost);
	}

	Find_Path();

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			if (iGraph[i][j] == 98765432)
				cout << "0" << " ";
			else
				cout << iGraph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}