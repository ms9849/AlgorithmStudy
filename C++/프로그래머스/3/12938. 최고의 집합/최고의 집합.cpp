#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	if (n > s)
		return {-1};

	vector<int> answer;

	while (n != 0)
	{
		int iNextNum = s / n;

		answer.push_back(iNextNum);
		
		s -= iNextNum;
		n--;
	}

	sort(answer.begin(), answer.end());

	return answer;
}
