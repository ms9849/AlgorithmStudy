#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> iNums{};

int main(void* pArg)
{
	int iN;
	int iTarget;
	int iResult = 0;

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iNums.push_back(iSour);
	}

	cin >> iTarget;

	sort(iNums.begin(), iNums.end(), [](int iLhs, int iRhs)->bool {
		return  iLhs < iRhs;
	});

	int iLessIdx = 0;
	int iGreaterIdx = iN - 1;

	while (iLessIdx < iGreaterIdx)
	{
		if (iNums[iLessIdx] + iNums[iGreaterIdx] <= iTarget)
		{
			if (iNums[iLessIdx] + iNums[iGreaterIdx] == iTarget)
				iResult++;

			iLessIdx++;
		}
		else if (iNums[iLessIdx] + iNums[iGreaterIdx] > iTarget)
			iGreaterIdx--;
		
	}

	cout << iResult << "\n";

	return 0;
}