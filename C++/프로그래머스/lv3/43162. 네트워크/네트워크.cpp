#include <string>
#include <vector>
//인접행렬의 형태로 제공..
//DFS로 가볼까?

int iVisited[201] = {};
using namespace std;

void DFS(int iCurNode, vector<vector<int>>& computers)
{
	int iIdxCount = 0;
	for(auto& iter : computers[iCurNode])
	{
		if (iIdxCount != iCurNode && iter == 1 && iVisited[iIdxCount] != 1)
		{
			iVisited[iIdxCount] = 1;
			DFS(iIdxCount, computers);
		}

		iIdxCount++;
	}
}

int solution(int n, vector<vector<int>> computers) {
	int iCount = 0;
	for (int i = 0; i < n; ++i)
	{
		if (0 == iVisited[i])
		{
			iVisited[i] = 1;
			DFS(i, computers);
			iCount++;
		}
	}

	return iCount;
}
