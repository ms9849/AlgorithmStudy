#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN, iM;
vector<int> vecNums = {};
vector<int> vecResults = {};

bool isVisited[10001] = {};

void Recursion(int iDepth)
{
	if (iDepth == iM)
	{
		for (auto& iter : vecResults)
			cout << iter << " ";

		cout << "\n";

		return;
	}

	for (int i = 1; i <= vecNums.size(); ++i)
	{
		if (isVisited[vecNums[i - 1]] == false)
		{
			isVisited[vecNums[i - 1]] = true;
			vecResults.push_back(vecNums[i - 1]);

			Recursion(iDepth + 1);

			isVisited[vecNums[i - 1]] = false;
			vecResults.pop_back();
		}
	}
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	sort(vecNums.begin(), vecNums.end(), [](int lhs, int rhs) -> bool {
		return lhs < rhs;
	});

	Recursion(0);

	return 0;
}