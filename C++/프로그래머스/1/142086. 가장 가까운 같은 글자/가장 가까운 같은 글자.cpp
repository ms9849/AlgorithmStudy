#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	int iArray[30] = {};

	for (int i = 0; i < 30; ++i)
		iArray[i] = -1;

	for (int i = 0; i < s.length(); ++i)
	{
		//안나왔으면 -1
		if (iArray[s[i] -'a'] == -1)
			answer.push_back(-1);
		else
			answer.push_back(i - iArray[s[i] - 'a']);

		iArray[s[i] - 'a'] = i;
	}

	return answer;
}
