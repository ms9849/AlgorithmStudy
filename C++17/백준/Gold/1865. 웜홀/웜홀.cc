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

	int iT;

	cin >> iT;

	while (iT > 0)
	{
		vector<pair<pair<int, int>, int>> vecEdges = {};
		int iVisited[501] = {};
		int iN, iM, iW;
		int iSour = {};

		cin >> iN >> iM >> iW;

		for (int i = 0; i < iM; ++i)
		{
			int iStart, iEnd, iCost;
			cin >> iStart >> iEnd >> iCost;
			vecEdges.push_back({ { iStart, iEnd }, iCost });
			vecEdges.push_back({ { iEnd, iStart }, iCost });
			if (i == 0)
				iSour = iStart;
		}

		for (int i = 0; i < iW; ++i)
		{
			int iStart, iEnd, iCost;
			cin >> iStart >> iEnd >> iCost;
			vecEdges.push_back({ { iStart, iEnd }, -iCost });
		}

		for (int i = 1; i <= 500; ++i)
			iVisited[i] = 0;

		iVisited[iSour] = 0;
		//정점의 갯수 - 1번 반복.
		for (int i = 0; i < iN - 1; ++i)
		{
			for (auto& iter : vecEdges)
			{
				if (iVisited[iter.first.first] == 260000000)
					continue;

				if (iVisited[iter.first.second] > iVisited[iter.first.first] + iter.second)
				{
					iVisited[iter.first.second] = iVisited[iter.first.first] + iter.second;
				}
			}
		}


		bool isMinusCycle = { false }; 
		for (auto& iter : vecEdges)
		{
			if (iVisited[iter.first.first] == 260000000)
				continue;

			if (iVisited[iter.first.second] > iVisited[iter.first.first] + iter.second)
			{
				iVisited[iter.first.second] = iVisited[iter.first.first] + iter.second;
				isMinusCycle = true;
			}
		}

		
		if (true == isMinusCycle)
			cout << "YES\n";
		else
			cout << "NO\n";

		iT--;
	}


	return 0;
}