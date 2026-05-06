#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), -1);
	//값, 인덱스 순으로 저장.
	stack<pair<int, int>> st = {};

	for (int i = 0; i < prices.size(); ++i)
	{
		while (!st.empty() && st.top().second > prices[i])
		{
			answer[st.top().first] = (i - st.top().first);

			//값 넣어잇
			st.pop();
		}
		st.push({ i, prices[i] });
	}

	for (int i = 0; i < prices.size(); ++i)
	{
		if (answer[i] == -1)
			answer[i] = prices.size() - i - 1;
	}

	return answer;
}