#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//간선을 전부 2차원 배열 형태로 저장할 수 없음..
//그럼.. 벡터나 큐? -> 접근은 어쩌게?

// 시작 노드에서 N번 인덱스 노드로 향하는 간선의 비용.
// -1이라면 INF 취급.
int iMinDists[20001] = {0,};


//간선 간의 비용.
/*
인덱스는 해당 노드가 몇번 노드인지 나타냄.
Pair의 First는 몇번 노드로 향하는 간선인지 나타냄.
Pair의 Second는 비용을 나타냄.
*/
vector<pair<int, int>> vecEdges[20001] = {};

void Find_Path(int iStartNode)
{
	// 우선순위 큐. 내부적으로 힙으로 구현되어 있어 O(log N)의 탐색 및 삽입 시간이 소요됨.
	// <현재까지 계산된 최소 거리, 정점> 으로 표시.
	priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pqShortest = {};
	
	iMinDists[iStartNode] = 0;
	
	pqShortest.push(make_pair(iMinDists[iStartNode], iStartNode));

	while (false == pqShortest.empty())
	{
		//정렬된 우선순위 큐에서 최소거리와 몇번째 정점인지 꺼내온다.
		pair<int,int> Pair = pqShortest.top();

		//현재 방문중인 노드의 거리
		int iMinCost = Pair.first;
		//방문중인 노드
		int iCurrentNode = Pair.second;

		pqShortest.pop();

		for (int i = 0; i < vecEdges[iCurrentNode].size(); ++i)
		{
			int iCost = vecEdges[iCurrentNode][i].second;
			int iNextNode = vecEdges[iCurrentNode][i].first;

			if (iCost + iMinCost < iMinDists[iNextNode])
			{
				iMinDists[iNextNode] = iCost + iMinCost;
				pqShortest.push(make_pair( iMinDists[iNextNode], iNextNode ));
			}
		}
	}
}

int main(void* pArg)
{
	ios::sync_with_stdio();
	cin.tie(0);

	int iV{}, iE{};
	int iStartNode{};

	cin >> iV >> iE;
	cin >> iStartNode;

	for (int i = 0; i < iE; ++i)
	{
		int iSour{}, iDest{}, iCost{};

		cin >> iSour >> iDest >> iCost;

		vecEdges[iSour].emplace_back(iDest, iCost);
	}

	for (int i = 0; i <= 20000; ++i)
	{
		iMinDists[i] = 999999999;
	}

	Find_Path(iStartNode);

	for (int i = 1; i <= iV; ++i)
	{
		if (iMinDists[i] == 999999999)
			cout << "INF" << "\n";
		else
			cout << iMinDists[i] << "\n";
	}

	return 0;
}