#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN;

vector<int> vecNums = {};

int main(void* pArg)
{
	cin >> iN;

	int iLow = 0;
	int iHigh = iN - 1;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	sort(vecNums.begin(), vecNums.end(), [](int lhs, int rhs)->bool {
		return lhs < rhs;
	});

	int iResultLow = {}, iResultHigh = {};
	int iMin = 2000000010;

	while (iLow < iHigh)
	{
		if (abs(vecNums[iLow] + vecNums[iHigh]) < abs(iMin))
		{
			iResultLow = iLow;
			iResultHigh = iHigh;
			iMin = vecNums[iLow] + vecNums[iHigh];
		}

		if (vecNums[iLow] + vecNums[iHigh] > 0)
		{

			iHigh--;
		}
		else if (vecNums[iLow] + vecNums[iHigh] < 0)
		{
			iLow++;
		}
		else
			break;
	}

	cout << vecNums[iResultLow] << " " << vecNums[iResultHigh] << "\n";

	return 0;
}