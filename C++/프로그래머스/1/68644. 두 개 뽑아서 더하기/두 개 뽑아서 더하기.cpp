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
Right 범위는 맞음..
그럼 Left는 최소값인데 범위가?..
*/
vector<int> solution(vector<int> numbers) {
	set<int> S = {};
	vector<int> answer = {};

	for (int i = 0; i < numbers.size(); ++i)
	{
		for(int j = 0; j<numbers.size(); ++j)
		{
			if(i != j)
				S.insert(numbers[i] + numbers[j]);
		}
	}

	for (auto& iter : S)
	{
		answer.push_back(iter);
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution({ 2,1,3,4,1 });
	return 0;
}