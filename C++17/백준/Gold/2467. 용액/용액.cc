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

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	sort(vecNums.begin(), vecNums.end());

	int iStart = 0;
	int iEnd = vecNums.size() -1;

	int iMinValue = 2000000001;

	int iMinIdx;
	int iMaxIdx;
	while (iStart < iEnd)
	{
		if (iMinValue > abs(vecNums[iStart] + vecNums[iEnd]))
		{
			iMinValue = abs(vecNums[iStart] + vecNums[iEnd]);
			iMinIdx = iStart;
			iMaxIdx = iEnd;
		}

		if (vecNums[iStart] + vecNums[iEnd] < 0)
		{
			iStart++;
		}
		else if (vecNums[iStart] + vecNums[iEnd] > 0)
		{
			iEnd--;
		}
		else
			break;
	}

	cout << vecNums[iMinIdx] << " " << vecNums[iMaxIdx]; 

	return 0;
}