#include <iostream>

using namespace std;

int main(void* pArg)
{
	int iN, iK, iX;

	int iCount = {0};
	int iGrade = {};

	int iNum[10001] = {};

	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iGrade;
		iNum[iGrade]++;
	}

	for (int i = 10000; i >= 0; --i)
	{
		if(iNum[i] != 0)
			iCount+= iNum[i];

		if (iCount >= iK)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}