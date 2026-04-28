#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>

//어쨌든 가장 긴 녀석은 곱해줘야 함..
// 다 스왑이 가능하다는거니까?..
// 8개면
// 0번쨰 인덱스 * 4번째 인덱스?

using namespace std;

int solution(vector<int> priorities, int location) {
	int iCount = 0;
	vector<pair<int,bool>> q = {};

	int iIdx = 0;
	for (auto& iter : priorities)
	{
		if (iIdx != location)
			q.push_back({ iter, false });
		else
			q.push_back({ iter, true });

		iIdx++;
	}

	while (!q.empty())
	{
		pair<int, bool> Node = q.front();
		int iMax = 0;

		for (auto& iter : q)
		{
			if(iMax < iter.first)
				iMax = iter.first;
		}

		q.erase(q.begin());

		if (Node.first == iMax)
		{
			iCount++;

			if (Node.second == true)
				return iCount;
		}
		else
		{
			q.push_back(Node);
		}
	}
}