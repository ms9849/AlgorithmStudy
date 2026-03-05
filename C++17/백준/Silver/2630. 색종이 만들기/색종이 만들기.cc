#include <iostream>

using namespace std;

int iBoard[129][129] = {};
int iN;

int iCountOne = 0;
int iCountZero = 0;

void Find_Paper(int iStartY, int iStartX, int iSize)
{
	if (iSize == 1)
	{
		if (iBoard[iStartY][iStartX] == 1)
			iCountOne++;
		else
			iCountZero++;

		return;
	}

	int iStartColor = iBoard[iStartY][iStartX];
	bool isOneColor = true;

	for (int i = iStartY; i < iStartY + iSize; ++i)
	{
		for (int j = iStartX; j < iStartX + iSize; ++j)
		{
			if (iBoard[i][j] != iStartColor)
			{
				isOneColor = false;
				break;
			}
		}

		if (isOneColor == false)
			break;
	}

	if (false == isOneColor)
	{
		Find_Paper(iStartY, iStartX, iSize / 2);
		Find_Paper(iStartY + iSize / 2, iStartX, iSize / 2);
		Find_Paper(iStartY, iStartX + iSize / 2, iSize / 2);
		Find_Paper(iStartY + iSize / 2, iStartX + iSize / 2, iSize / 2);
	}
	else
	{
		if (iBoard[iStartY][iStartX] == 1)
			iCountOne++;
		else
			iCountZero++;

		return;
	}
}

int main(void* pArg)
{
	cin >> iN;

	int iVal;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> iVal;
			iBoard[i][j] = iVal;
		}
	}

	Find_Paper(0, 0, iN);

	cout << iCountZero << "\n" << iCountOne;
	
	return 0;
}