#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

//덧셈 뺄셈 곱셈 나눗셈 순서.
// 0 ,  1 ,  2 ,  3
int iCalculator[4] = { 0, };
int iN;
vector<int> iNum = {};

int iMin = 1000000001;
int iMax = -1000000001;

void BackTracking(int iDepth, int iValue)
{
	if (iDepth == iN - 1)
	{
		if (iMin >= iValue)
			iMin = iValue;

		if (iMax <= iValue)
			iMax = iValue;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (iCalculator[i] != 0)
		{
			iCalculator[i]--; 
			
			switch (i)
			{
			case 0:
				BackTracking(iDepth + 1, iValue + iNum[iDepth+1]);
				break;
			case 1:
				BackTracking(iDepth + 1, iValue - iNum[iDepth + 1]);
				break;
			case 2:
				BackTracking(iDepth + 1, iValue * iNum[iDepth + 1]);
				break;
			case 3:
				BackTracking(iDepth + 1, iValue / iNum[iDepth + 1]);
				break;
			default:
				break;
			}

			iCalculator[i]++;
		}
	}
}

int main(void* pArg)
{
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		iNum.push_back(iSour);
	}

	for (int i = 0; i < 4; ++i)
	{
		int iSour;
		cin >> iSour;

		iCalculator[i] = iSour;
	}

	BackTracking(0, iNum[0]);

	cout << iMax << "\n" << iMin << "\n";

	return 0;
}