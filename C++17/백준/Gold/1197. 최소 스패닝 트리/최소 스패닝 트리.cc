#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN, iE;

vector<pair<int, int>> vecGraphs[10001] = {};

int iVisited[10001] = { 0, };
int iCount = 0;
int iMinCost = 0;

int main(void* pArg)
{
	cin >> iN >> iE;

	for (int i = 0; i < iE; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;

		vecGraphs[iSour].emplace_back(make_pair(iDest, iCost));
		vecGraphs[iDest].emplace_back(make_pair(iSour, iCost));
	}

	//프림 알고리즘 구현부
	// cost, 정점 순
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.emplace(make_pair(0, 1));

	while (iCount < iN)
	{
		//가장 싼 간선이 가장 위에 있으니까..
		int iCost = pq.top().first;
		int iVisitNode = pq.top().second;
	
		pq.pop();

		if (iVisited[iVisitNode] == true)
			continue;

		iVisited[iVisitNode] = true;
		iMinCost += iCost;
		iCount++;

		for (auto& iter : vecGraphs[iVisitNode])
		{
			int iCost = iter.second;
			int iNextNode = iter.first;

			if(!iVisited[iNextNode])
				pq.push(make_pair(iCost, iNextNode));
		}
	}
	cout << iMinCost << "\n";

	return 0;
}