#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN, iM;

vector<pair<pair<int, int>, int>> vecEdges = {};

long long iDist[501] = {};

int main(void* pArg)
{
	cin >> iN >> iM;

	for (int i = 0; i < iM; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;

		vecEdges.push_back(make_pair(make_pair(iSour, iDest), iCost));
	}

	for (int i = 0; i <= 500; ++i)
	{
		iDist[i] = 987654321;
	}

	iDist[1] = 0;

	for (int i = 0; i < iN - 1; ++i)
	{
		for (auto& iter : vecEdges)
		{
			if (iDist[iter.first.first] == 987654321)
				continue;

			if (iDist[iter.first.second] > iDist[iter.first.first] + iter.second)
			{
				iDist[iter.first.second] = iDist[iter.first.first] + iter.second;
			}
		}
	}

	bool hasCycle = false;
	for (auto& iter : vecEdges)
	{
		if (iDist[iter.first.first] == 987654321)
			continue;

		if (iDist[iter.first.second] > iDist[iter.first.first] + iter.second)
		{
			hasCycle = true;
		}
	}

	if(true == hasCycle)
		cout << "-1";

	else
	{
		for (int i = 2; i <= iN; ++i)
		{
			if (iDist[i] == 987654321)
				cout << "-1\n";
			else
				cout << iDist[i] << "\n";
		}
	}

	return 0;
}