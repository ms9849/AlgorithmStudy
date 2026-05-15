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

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> vecNums = {};
	vector<pair<int, int>> vecDirs = { {1,0}, {0,1}, {-1,-1} };
	int iCurY{}, iCurX{};
	int iCurDirection = 0;
	int iNumber = 1;
	vecNums.resize(n);
	int iSum = 0;

	for (int i = 0; i < n; ++i)
	{
		vecNums[i].resize(i + 1);
		iSum += (i+1);
	}

	for (int i = 0; i < iSum; ++i)
	{
		vecNums[iCurY][iCurX] = iNumber++;

		if (iCurY + vecDirs[iCurDirection].first < 0 ||
			iCurY + vecDirs[iCurDirection].first >= n ||
			iCurX + vecDirs[iCurDirection].second < 0 ||
			iCurX + vecDirs[iCurDirection].second >= n ||
			vecNums[iCurY + vecDirs[iCurDirection].first][iCurX + vecDirs[iCurDirection].second] != 0)
		{
			iCurDirection++;

			if (iCurDirection > 2)
				iCurDirection = 0;
		}

		iCurY = iCurY + vecDirs[iCurDirection].first;
		iCurX = iCurX + vecDirs[iCurDirection].second;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			answer.push_back(vecNums[i][j]);
		}
	}

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution(4);
	return 0;
}