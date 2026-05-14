#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>
#include "limits.h"

using namespace std;

/*
Right 범위는 맞음..
그럼 Left는 최소값인데 범위가?..
*/
long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long iMax = 0;
	long long iMin = INT_MAX;

	for (auto& iter : times)
	{
		if (iter > iMax)
			iMax = iter;

		if (iter < iMin)
			iMin = iter;
	}

	long long iLow = iMin;
	long long iHigh = iMax * n;


	long long iMid = {};

	while (iLow <= iHigh)
	{
		iMid = (iLow + iHigh) / 2;

		long long iCount = 0;
		for (auto& iter : times)
			iCount += iMid / iter;

		//엥 더 채울수있네? 그럼 더 낮춰봐
		if (iCount >= n)
		{
			answer = iMid;
			iHigh = iMid - 1;
		}
		//사람 다 못채우면 시간 늘려야지
		else
		{
			iLow = iMid + 1;
		}

	}

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution(6, {7, 10});
	return 0;
}