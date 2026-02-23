#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//그래프 형태로 저장. (배열은 안쓰도록 자제)
// 인덱스 -> 현재 노드
// pair first -> 다음 노드 
// pair second -> 비용
vector<pair<int, int>> vecEdges[300000] = {};
int iMinDist[300001] = {};

void Find_Path(int iStartNode)
{
	iMinDist[iStartNode] = 0;
	//첫 인자는 현재까지 계산된 최소 비용, 두번째 인자는 방문중인 노드
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, iStartNode));

	while (!pq.empty())
	{
		int iCurrentCost = pq.top().first;
		int iCurrentNode = pq.top().second;

		pq.pop();

		for (auto& iter : vecEdges[iCurrentNode])
		{
			int iNextNode = iter.first;
			int iCost = iter.second;

			//만약 최단거리 + 다음 노드로 가는 비용이, 다음 노드의 현재 최소 비용보다 적다면
			if (iCurrentCost + iCost < iMinDist[iNextNode])
			{
				//다음 노드의 최소 비용 갱신
				iMinDist[iNextNode] = iCurrentCost + iCost;

				//다음 노드도 방문 후보에 추가.
				pq.push(make_pair(iMinDist[iNextNode], iNextNode));
			}
		}
	}
}

int main(void* pArg)
{
	ios::sync_with_stdio();
	cin.tie(NULL);

	int iN{}, iE{}, iTarget{}, iStart{};

	cin >> iN >> iE >> iTarget >> iStart;

	for (int i = 1; i <= iN; ++i)
		iMinDist[i] = iN + 10;

	for (int i = 0; i < iE; ++i)
	{
		int iSour{}, iDest{};
		cin >> iSour >> iDest;

		vecEdges[iSour].emplace_back(make_pair(iDest, 1));
	}

	Find_Path(iStart);

	bool isExist = { false };
	for (int i = 1; i <= iN; ++i)
	{
		if (iMinDist[i] == iTarget)
		{
			cout << i << "\n";
			isExist = true;
		}
	}

	if (false == isExist)
	{
		cout << "-1\n";
	}

	return 0;
}