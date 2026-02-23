#include <iostream>
#include <vector>
#include <queue>

#define DIST_MAX 987654321
using namespace std;

int iN{}, iE{};
long long iMinDist[501] = {};

vector<pair<pair<int, int>, int>> vecEdges = {};

void Find_Path(int iStartNode)
{
	iMinDist[iStartNode] = 0;
	// 노드 N-1 개만큼 반복. (노드가 N개인 그래프에서 한 경로의 최대 간선 갯수는 N-1개 이므로.)
	// 약간 BFS 느낌?
	for (int i = 0; i < iN - 1; ++i)
	{
		//모든 간선을 순회하면서, 방문 가능한지 체크.
		for (auto& iter : vecEdges)
		{
			// 만약 방문할 노드의 거리가 갱신되어있지 않다면 생략.
			if (iMinDist[iter.first.first] == DIST_MAX)
				continue;

			// 현재 노드에서 다른 노드로 가는 최소 거리의 갱신이 가능하다면,
			if (iMinDist[iter.first.second] > iMinDist[iter.first.first] + iter.second)
			{
				// 갱신.
				iMinDist[iter.first.second] = iMinDist[iter.first.first] + iter.second;
			}
		}
	}
}

int main(void* pArg)
{
	ios::sync_with_stdio();
	cin.tie(NULL);

	cin >> iN >> iE;

	for (int i = 0; i < iE; ++i)
	{
		int iSour{}, iDest{}, iCost{};
	
		cin >> iSour >> iDest >> iCost;

		vecEdges.emplace_back(make_pair(make_pair(iSour, iDest), iCost));
	}

	for (int i = 0; i <= 500; ++i)
	{
		iMinDist[i] = DIST_MAX;
	}

	Find_Path(1);

	for (auto& iter : vecEdges)
	{
		if (iMinDist[iter.first.first] == DIST_MAX)
			continue;

		if (iMinDist[iter.first.second] > iMinDist[iter.first.first] + iter.second)
		{
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 2; i <= iN; ++i)
	{
		if (iMinDist[i] == DIST_MAX)
			cout << "-1\n";
		else
			cout << iMinDist[i] << "\n";
	}


	return 0;
}