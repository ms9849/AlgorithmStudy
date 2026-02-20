#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> iNums;

int main(void* pArg)
{
	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iNums.push_back(iSour);
	}

	sort(iNums.begin(), iNums.end(), [](int iLhs, int iRhs)->bool {
		return iLhs < iRhs;
	});

	int iResultLessIdx, iResultGreaterIdx;
	int iMin = 2000000001;

	int iLessIdx = 0;
	int iGreaterIdx = iN - 1;

	while (iLessIdx < iGreaterIdx)
	{
		int iSum = iNums[iLessIdx] + iNums[iGreaterIdx];

		if (abs(iSum) <= iMin)
		{
			iResultLessIdx = iLessIdx;
			iResultGreaterIdx = iGreaterIdx;
			iMin = abs(iSum);
		}

		if (iSum < 0)
		{
			iLessIdx++;
		}
		else if (iSum > 0)
			iGreaterIdx--;
		else
			break;
	}

	cout << iNums[iResultLessIdx] << " " << iNums[iResultGreaterIdx];

	return 0;
}