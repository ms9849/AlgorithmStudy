#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>
#include <set>

using namespace std;

/*
첫 방향 -> 내려 가기만
두번째 방향 -> 옆으로 가기만
세번째 방향 -> 대각선 왼쪽 위로 가기만.

이후 반복.
*/

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	map<string, int> mapCost = {};

	for (int i = 0; i < name.size(); ++i)
	{
		mapCost.emplace(name[i], yearning[i]);
	}

	for (int i = 0; i < photo.size(); ++i)
	{
		answer.push_back(0);
		for (int j = 0; j < photo[i].size(); ++j)
		{
			answer[i] += mapCost[photo[i][j]];
		}
	}

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 },
		{ {"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"} });

	return 0;
}