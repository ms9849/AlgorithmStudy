#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<long long> vecNums = {};
	long long iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		long long iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	sort(vecNums.begin(), vecNums.end());

	long long iEnd = vecNums.size() - 1;


	long long iMin = 3000000000;
	vector<int> Answer = {};

	for (int i = 0; i < iEnd; ++i)
	{
		int iLow = i + 1;
		int iHigh = iEnd;

		while (iLow < iHigh)
		{
			long long iSum = vecNums[iLow] + vecNums[iHigh] + vecNums[i];

			if (abs(iSum) < abs(iMin))
			{
				iMin = vecNums[iLow] + vecNums[iHigh] + vecNums[i];

				Answer = {};
				Answer.push_back(vecNums[iLow]);
				Answer.push_back(vecNums[iHigh]);
				Answer.push_back(vecNums[i]);
			}


			if (iSum < 0)
			{
				iLow++;
			}
			else if (iSum > 0)
			{
				iHigh--;
			}
			else
				break;
		}
	}

	sort(Answer.begin(), Answer.end());

	for (auto& iter : Answer)
		cout << iter << " ";

	return 0;
}