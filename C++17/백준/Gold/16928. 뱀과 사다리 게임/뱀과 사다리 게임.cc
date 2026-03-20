#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
1. 1~6칸 이동 가능,
2. 뒤로 가는 웜홀이 존재.
3. 앞으로 가는 웜홀이 존재.
*/

int iDist[101] = {};
int iSnake[101] = {};
int iRadder[101] = {};

int main(void* pArg)
{
	// 어쨌든 경우의 수가 많진 않긴한데..
	// 뱀을 타면 무조건 손해인가? -> ㄴㄴ. 포탈 -> 뱀 -> 포탈 서순도 가능.
	// 뱀을 타면 루프 가능성이 존재함. 
	// 그럼 동시에 뻗어나가는 BFS가 가능성이 있겠지? 최단 경로만 구하면 되니까..
	// BFS로 해보자.
	vector<int> vecRadders = {};
	vector<int> vecSnakes = {};
	queue<int> q = {};
	int iN{}, iM{};
	int iSour, iDest;

	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		cin >> iSour >> iDest;
		iRadder[iSour] = iDest;
	}

	for (int i = 0; i < iM; ++i)
	{
		cin >> iSour >> iDest;
		iRadder[iSour] = iDest;
	}

	int iStart = 1;

	q.push(iStart);
	iDist[iStart] = 1;

	while (!q.empty())
	{
		int iCurrentNode = q.front();
		q.pop();

		for (int i = 1; i <= 6; ++i)
		{
			int iNextNode = iCurrentNode + i;

			//뱀
			if (iSnake[iNextNode] != 0 )
			{
				iNextNode = iSnake[iNextNode];
			}
			//사다리
			if (iRadder[iNextNode] != 0)
			{
				iNextNode = iRadder[iNextNode];
			}

			//첫 방문이거나, 현재 노드에서 뻗어나가는게 최단 거리였다면.
			if ((iDist[iNextNode] == 0 || (iDist[iNextNode] > iDist[iCurrentNode] + 1))
				&& iNextNode <= 100)
			{
				iDist[iNextNode] = iDist[iCurrentNode] + 1;
				q.push(iNextNode);
			}
		}
	}

	cout << iDist[100] - 1 << "\n";

	return 0;
}