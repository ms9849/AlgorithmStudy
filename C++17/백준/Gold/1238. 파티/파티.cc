#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vecEdges[1001] = {};
vector<pair<int, int>> vecReverseEdges[1001] = {};

int iDist[1001] = {};
int iReversedDist[1001] = {};

#define MAX_DIST 1000000000

int main(void* pArg)
{
	int iN, iM, iX;
	cin >> iN >> iM >> iX;

	for (int i = 0; i <= 1000; ++i)
	{
		iDist[i] = MAX_DIST;
		iReversedDist[i] = MAX_DIST;
	}

	for (int i = 0; i < iM; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;

		vecEdges[iSour].push_back({ iDest, iCost });
		vecReverseEdges[iDest].push_back({ iSour, iCost });
	}

	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq = {};
	pq.push(make_pair( 0, iX ));
	iDist[iX] = 0;

	while (!pq.empty())
	{
		int iCost = pq.top().first;
		int iCurNode = pq.top().second;

		pq.pop();

		for (auto& iter : vecEdges[iCurNode])
		{
			int iNextNode = iter.first;
			int iNextNodeCost = iter.second;

			if (iDist[iNextNode] > iDist[iCurNode] + iNextNodeCost)
			{
				iDist[iNextNode] = iDist[iCurNode] + iNextNodeCost;
				pq.push(make_pair(iDist[iNextNode], iNextNode));
			}
		}
	}

	pq = {};
	pq.push(make_pair(0, iX));
	iReversedDist[iX] = 0;

	while (!pq.empty())
	{
		int iCost = pq.top().first;
		int iCurNode = pq.top().second;

		pq.pop();

		for (auto& iter : vecReverseEdges[iCurNode])
		{
			int iNextNode = iter.first;
			int iNextNodeCost = iter.second;

			if (iReversedDist[iNextNode] > iReversedDist[iCurNode] + iNextNodeCost)
			{
				iReversedDist[iNextNode] = iReversedDist[iCurNode] + iNextNodeCost;
				pq.push(make_pair(iReversedDist[iNextNode], iNextNode));
			}
		}
	}

	int iMax = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (iMax < iDist[i] + iReversedDist[i])
		{
			iMax = iDist[i] + iReversedDist[i];
		}
	}

	cout << iMax;

	return 0;
}