#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq = {};

	for (int i = 0; i < scoville.size(); ++i)
	{
		pq.push(scoville[i]);
	}

	while (pq.top() < K)
	{
		unsigned long long iMin = pq.top();
		if (pq.empty())
			return -1;
		pq.pop();

		unsigned long long iSecondMin = pq.top();
		if (pq.empty())
			return -1;
		pq.pop();

		pq.push(iMin + iSecondMin * 2);

		answer++;
	}


	return answer;
}