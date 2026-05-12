#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

using namespace std;

//dfs로 모든 경로 확인.
//전 경로 방문이 확인됐다면 반환.

//map<string, vector<string>> 으로 방문 경로 확인

map<pair<string, string>, int> mapRoads = {};
int iMaxDepth = 0;

vector<string> visited = {};
vector<string> Answer = {};

void DFS(string CurNode, int iDepth)
{
	if (iDepth == iMaxDepth)
	{
		//값 복사가 일어나겠지..?
		if (Answer.size() == 0)
			Answer = visited;

		//값 복사가 일어나지 않았다면
		else
		{
			string strAnswer = {};
			string strNode = {};

			for (int i = 0; i < Answer.size(); ++i)
				strAnswer += Answer[i];

			for (int i = 0; i < visited.size(); ++i)
				strNode += visited[i];

			if (strAnswer > strNode)
				Answer = visited;
		}

		return;
	}

	// 반복문 이렇게 돌리면 모든 경로에 대해서 순회가 가능하긴 한데..
	for (auto& iter : mapRoads)
	{
		if (iter.first.first == CurNode && iter.second != 0)
		{
			visited.push_back(iter.first.second);
			iter.second--;

			DFS(iter.first.second, iDepth + 1);

			visited.pop_back();
			iter.second++;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	for (auto& iter : tickets)
	{
		mapRoads[make_pair(iter[0], iter[1])]++;
	}

	iMaxDepth = (tickets.size() + 1);

	visited.push_back("ICN");
	DFS("ICN", 1);

	return Answer;
}

