#include <iostream>

using namespace std;

char cArray[3073][9217] = {};

void Recursion(int iLevel, int iStartY, int iStartX)
{
	if (iLevel == 3)
	{
		cArray[iStartY][iStartX] = '*';

		cArray[iStartY + 1][iStartX + 1] = '*';
		cArray[iStartY + 1][iStartX - 1] = '*';

		cArray[iStartY + 2][iStartX - 2] = '*';
		cArray[iStartY + 2][iStartX - 1] = '*';
		cArray[iStartY + 2][iStartX] = '*';
		cArray[iStartY + 2][iStartX + 1] = '*';
		cArray[iStartY + 2][iStartX + 2] = '*';
	}
	else
	{
		Recursion(iLevel / 2, iStartY, iStartX);
		Recursion(iLevel / 2, iStartY + iLevel / 2, iStartX + iLevel / 2);
		Recursion(iLevel / 2, iStartY + iLevel / 2, iStartX - iLevel / 2);
	}
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN;

	cin >> iN;

	Recursion(iN, 0, iN);

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 1; j <= iN * 2; ++j)
		{
			if (cArray[i][j] == '*')
				cout << cArray[i][j];
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}