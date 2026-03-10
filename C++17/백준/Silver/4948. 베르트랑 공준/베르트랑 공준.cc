#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

bool isLone[246913] = {};

int main(void* pArg)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	isLone[1] = 1;

	for (int i = 2; i <= 246913; ++i)
	{
		int iStart = i;
		int iCount = 2;
		int iVal = iStart * iCount;

		while (iVal <= 246913)
		{
			isLone[iVal] = 1;
			iVal = iStart * iCount;
			iCount++;
		} 
	}

	while (1)
	{
		int iSour;
		int iCount = 0;
		
		cin >> iSour;

		if (iSour == 0)
			break;

		for (int i = iSour + 1; i <= iSour * 2; ++i)
		{
			if (0 == isLone[i])
				iCount++;
		}

		cout << iCount << "\n";
	}

	return 0;
}