#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int iCount = 0;
	while (!progresses.empty())
	{
		iCount++;


		int iIdx = 0;
		for (auto& iter : progresses)
		{
			progresses[iIdx] += speeds[iIdx];

			iIdx++;
		}

		int iDeleteCount = { 0 };

		while (!progresses.empty() && progresses[0] >= 100)
		{
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
			iDeleteCount++;
		}

		if (0 < iDeleteCount)
		{
			answer.push_back(iDeleteCount);
		}
	}

	return answer;
}