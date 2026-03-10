#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

bool isLone[1000001] = {};

int main(void* pArg)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	isLone[1] = true;

	for (int i = 2; i <= 1000000; ++i)
	{
		int iStart = i;
		int iCount = 2;
		int iVal = iStart * iCount;

		while (iStart * iCount <= 1000000)
		{
			iVal = iStart * iCount;
			isLone[iVal] = true;
			iCount++;
		} 
	}

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		int iResult = 0;
		cin >> iSour;

		for (int i = 2; i <= iSour / 2; ++i)
		{
			if (isLone[i] == false && isLone[iSour - i] == false)
				iResult++;
		}

		cout << iResult << "\n";
	}


	return 0;
}