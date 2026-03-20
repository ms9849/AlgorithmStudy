#include <iostream>
#include <vector>
using namespace std;

int iN, iR, iC;

int iResult = 0;
bool isFinished = { false };
vector<pair<int, int>> vecDirs = {
	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 1, 1 }
};

void Recursion(int iCurY, int iCurX, int iCount, int iSize)
{
	if (true == isFinished)
		return;

	if (iR == iCurY && iC == iCurX)
	{
		isFinished = true;
		iResult = iCount;
	}

	if (iR < iCurY + iSize / 2 && iC < iCurX + iSize / 2 && false == isFinished)
		Recursion(iCurY, iCurX, iCount, iSize / 2);

	if (iR < iCurY +  iSize / 2 && iC >= iCurX + iSize / 2 && false == isFinished)
		Recursion(iCurY, iCurX + iSize / 2, iCount + iSize / 2 * iSize / 2, iSize / 2);

	if (iR >= iCurY + iSize / 2 && iC < iCurX + iSize / 2 && false == isFinished)
		Recursion(iCurY + iSize / 2, iCurX, iCount + iSize / 2 * iSize / 2 * 2, iSize / 2);

	if (iR >= iCurY +  iSize / 2 && iC >= iCurX + iSize / 2 && false == isFinished)
		Recursion(iCurY + iSize / 2, iCurX + iSize / 2, iCount + iSize / 2 * iSize / 2 * 3, iSize / 2);
}

int main(void* pArg)
{
	cin >> iN >> iR >> iC;

	int iSize = 1;

	for (int i = 0; i < iN; ++i)
	{
		iSize *= 2;
	}

	Recursion(0, 0, 0, iSize);

	cout << iResult << "\n";

	return 0;
}