#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int, vector<int>, less<int>> pq = {};

	for (auto& iter : works)
	{
		pq.push(iter);
	}

	while (n != 0)
	{
		int iNum = pq.top();
		pq.pop();

		iNum--;
		n--;

		pq.push(iNum);
	}

	while (!pq.empty())
	{
		int iNum = pq.top();
        
        if (iNum < 0)
			return 0;
        
		pq.pop();

		answer += iNum* iNum;
	}

	return answer;

}
