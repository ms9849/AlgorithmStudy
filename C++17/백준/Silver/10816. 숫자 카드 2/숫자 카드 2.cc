#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> iArray{};

int LowerBound(int iTarget, int iStart, int iEnd)
{
	while (iStart <= iEnd)
	{
		int iMiddle = (iStart + iEnd) / 2;

		// 일반적인 이분 탐색이랑 다른건.. >= 사용하는거? 이래야 같아도 계속 내려가면서 탐색하지 ㅇㅇ.
		if (iArray[iMiddle] >= iTarget)
		{
			iEnd = iMiddle - 1;
		}
		else if(iArray[iMiddle] < iTarget)
			iStart = iMiddle + 1;
	}

	return iStart;
}

int UpperBound(int iTarget, int iStart, int iEnd)
{
	while (iStart <= iEnd)
	{
		int iMiddle = (iStart + iEnd) / 2;

		// 일반적인 이분 탐색이랑 다른건.. >= 사용하는거? 이래야 같아도 계속 내려가면서 탐색하지 ㅇㅇ.
		 if (iArray[iMiddle] <= iTarget)
			iStart = iMiddle + 1;
		 else if (iArray[iMiddle] > iTarget)
			 iEnd = iMiddle - 1;
	}

	return iStart;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iN, iM;

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour{};
		cin >> iSour;

		iArray.push_back(iSour);
	}

	//정렬.
	sort(iArray.begin(), iArray.end(), [](int iLhs, int iRhs)->bool {
		return iLhs < iRhs;
	});

	cin >> iM;

	for (int i = 0; i < iM; ++i)
	{
		int iSour{};
		cin >> iSour;

		cout << UpperBound(iSour, 0, iN - 1) - LowerBound(iSour, 0, iN - 1) << "\n";
	}

	return 0;
}