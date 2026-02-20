#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> iVector{};
int iN{}, iM{};
int iResult{};
//"필요한 만큼만" 가져가는 값들 중 최대값.
int BinarySearch(int iStart, int iEnd, int iTarget)
{
	int iMiddle{};

	while (iStart <= iEnd)
	{
		long long iSum = 0;
		iMiddle = (iStart + iEnd) / 2;

		for (int i = 0; i < iN; ++i)
		{
			if(iVector[i] >= iMiddle)
				iSum += iVector[i] - iMiddle;
		}

		if (iSum >= iTarget)
		{
			iResult = iMiddle;
			iStart = iMiddle + 1;
		
		}
		else if (iSum <= iTarget)
		{
			iEnd = iMiddle - 1;
		}
	}

	return iMiddle;
}

int main(void* pArg)
{
	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		int iSour{};
		cin >> iSour;

		iVector.push_back(iSour);
	}

	sort(iVector.begin(), iVector.end(), [](int iLhs, int iRhs)->bool {
		return iLhs < iRhs;
	});

	BinarySearch(0, iVector[iN - 1], iM);
	cout << iResult << "\n";

	return 0;
}