#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	else
		return GCD(b, r);
}

int main(void* pArg)
{
	int iN{};
	int iDiffMin{};
	int iResult{}, iResultCount{};
	vector<int> vecNums = {};
	vector<int> vecDiffs = {};
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;
		vecNums.push_back(iSour);
	}

	//가장 작은 차이를 구하고, 모든 차이와의 최소 공약수를 구해서 가로수를 세기.

	for (int i = 0; i < iN - 1; ++i)
	{
		vecDiffs.push_back(vecNums[i + 1] - vecNums[i]);
	}

	sort(vecDiffs.begin(), vecDiffs.end(), [](int a, int b) {
		return a < b;
		});

	iResult = vecDiffs[0];
	for (int i = 1; i < vecDiffs.size(); ++i)
	{
		iResult = GCD(vecDiffs[i], iResult);
	}

	for (int i = 0; i < vecDiffs.size(); ++i)
	{
		iResultCount += vecDiffs[i] / iResult - 1;
	}

	cout << iResultCount << endl;

	return 0;
}