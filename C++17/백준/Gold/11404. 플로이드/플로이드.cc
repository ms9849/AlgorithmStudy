#include <iostream>

using namespace std;

long long iDist[101][101] = { };

int main(void* pArg)
{
	int iN, iM;

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> iN >> iM;

	for (int i = 0; i <= 100; ++i)
		for (int j = 0; j <= 100; ++j)
			iDist[i][j] = 1e9;

	for (int i = 1; i <= iN; ++i)
		iDist[i][i] = 0;

	for (int i = 0; i < iM; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;

		if (iDist[iSour][iDest] > iCost)
			iDist[iSour][iDest] = iCost;
	}

	for (int k = 1; k <= iN; ++k)
	{
		for (int i = 1; i <= iN; ++i)
		{
			for (int j = 1; j <= iN; ++j)
			{
				if (iDist[i][j] > iDist[i][k] + iDist[k][j])
					iDist[i][j] = iDist[i][k] + iDist[k][j];

			}
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			if (iDist[i][j] == 1e9)
				cout << "0 ";
			else
				cout << iDist[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}