#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	vector<int> vecNums = {};
	int iN;
	int iDp[1001] = {};
	int iArray[1001] = {};
	int iMax = 1;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
		cin >> iArray[i];

	iDp[1] = 1;

	for (int i = 2; i <= iN; ++i)
	{
		iDp[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (iArray[i] < iArray[j])
			{
				iDp[i] = max(iDp[i], iDp[j] + 1);

				if (iDp[i] > iMax)
					iMax = iDp[i];
			}
		}
	}
	
	cout << iMax;

	return 0;
}