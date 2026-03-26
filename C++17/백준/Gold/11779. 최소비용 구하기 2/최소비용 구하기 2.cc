#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
최소 비용.
다익스트라는 최단 거리는 최단 거리들로만 구성되어있다는 그리디한 방법으로 수행.

-> iDist 구해내고,

3에서 4로 가는 최단경로라고 하면..

최단경로로만 움직이는건 불가능할거고.
dist가 갱신될떄 경로를 잡아둬야하나?
*/

vector<pair<long long, long long>> vecEdges[10001] = {};
vector<pair<long long, long long>> vecReversed[10001] = { };
long long iStart, iEnd;
long long iVisited[10001] = {};

vector<int> vecNodes{};

void DFS(int iCurNode, int iCount)
{
	vecNodes.push_back(iCurNode);

	if (iCurNode == iStart)
	{
		cout << iCount << "\n";
		for (int i = vecNodes.size() - 1; i >= 0; i--)
		{
			cout << vecNodes[i] << " ";
		}

		return;
	}

	for (auto& iter : vecReversed[iCurNode])
	{
		if (iVisited[iter.first] == (iVisited[iCurNode] - iter.second))
		{
			DFS(iter.first, iCount + 1);
			break;
		}
	}

	vecNodes.pop_back();
}

int main(void* pArg)
{
	int iV, iE;

	cin >> iV >> iE;

	for (int i = 1; i <= iV; ++i)
		iVisited[i] = 100000000000;

	for (int i = 0; i < iE; ++i)
	{
		long long iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;
		vecEdges[iSour].push_back(make_pair(iDest, iCost));
		vecReversed[iDest].push_back(make_pair(iSour, iCost));
	}

	cin >> iStart >> iEnd;
	iVisited[iStart] = 0;

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq = {};
	pq.push({ 0, iStart });

	while (!pq.empty())
	{
		long long iCurNode = pq.top().second;
		long long iCost = pq.top().first;

		pq.pop();

		if (iVisited[iCurNode] < iCost)
			continue;

		for (auto& iter : vecEdges[iCurNode])
		{
			if (iVisited[iter.first] > iCost + iter.second)
			{
				iVisited[iter.first] = iCost + iter.second;
				pq.push({ iVisited[iter.first], iter.first });
			}
		}
	}

	//최단 경로는 구했고..
	cout << iVisited[iEnd] << "\n";

	/*
	* 최단 경로에서 시작은 맞음.
	* 최단 경로에서 움직여서..
	* 최단 경로 - 간선의 경로와 거리가 같다면 최단 경로의 후보겠지?
	* 그걸 담아.
	*/

	//DFS로 가야하나?
	DFS(iEnd, 1);

	return 0;
}