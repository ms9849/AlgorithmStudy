#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> vecEdges[20001] = {};
int iVisited[20001] = {};


int solution(int n, vector<vector<int>> edge) {

	int iAnswer = 0; 

	for (auto& iter : edge)
	{
		// 양방향으로 갈 수 있게 처리해주자.
		// (3,6)
		vecEdges[iter[0]].push_back({ iter[1] });
		// (6,3)
		vecEdges[iter[1]].push_back({ iter[0] });
	}

	//방문할 노드, 거리(깊이).
	queue<pair<int, int>> q = {}; 
	int iMaxDepth = 0;

	q.push({ 1,1 });
	iVisited[1] = 1;

	while (!q.empty())
	{
		// 현재 노드.
		pair<int, int> CurNode = q.front();
		// pop 해버려.
		q.pop();

		//현재 노드에서 방문할 수 있는 녀석들을 찾아보자.
		for (auto& iter : vecEdges[CurNode.first])
		{
			if (iVisited[iter] == 0)
			{
				//최종 계산에서 거리 - 1 해줘야함.
				iVisited[iter] = CurNode.second + 1;

				q.push({ iter, CurNode.second + 1 });

				//최대 깊이 갱신.
				if (CurNode.second + 1 > iMaxDepth)
					iMaxDepth = CurNode.second + 1;
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (iVisited[i] == iMaxDepth)
		{
			iAnswer++;
		}
	}

	return iAnswer;
}