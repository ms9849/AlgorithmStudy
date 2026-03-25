#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
dp를 이용해서 각 
*/

map<int, int> mCoins = {};
vector<int> vecCoins = {};

int iDp[10010] = {};

int main(void* pArg)
{
	int iN, iK;
	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;
	
		auto iter = mCoins.find(iSour);
		if (iter == mCoins.end())
		{
			mCoins.emplace(iSour, 1);
		}
	}

	for (auto& iter : mCoins)
		vecCoins.push_back(iter.first);

	sort(vecCoins.begin(), vecCoins.end());

	for (int i = 0; i < vecCoins.size(); ++i)
	{
		if(vecCoins[i] <= iK)
			iDp[vecCoins[i]] = 1;
	}

	for (int i = 1; i <= iK; ++i)
	{
		if(iDp[i] == 0)
			iDp[i] = 10000000;

		for (int j = 0; j < vecCoins.size(); ++j)
		{
			if((i - vecCoins[j] > 0))
				iDp[i] = min(iDp[i], iDp[i - vecCoins[j]] + 1);
		}

	}
	
	if (iDp[iK] == 10000000)
		cout << "-1";
	else
		cout << iDp[iK];

	return 0;
}