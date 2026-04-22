#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int solution(int k, vector<int> tangerine) {
	int answer = { 0 };
	map<int, int> TangerineSizes = {};

	for(auto& iter : tangerine)
	{
		//사이즈 iter인 귤 갯수 1개 추가.
		TangerineSizes[iter]++;
	}

	vector<pair<int, int>> vecPairs = {};
	for (auto& iter : TangerineSizes)
	{
		//second가 갯수
		vecPairs.push_back({ iter.first, iter.second });
	}

	sort(vecPairs.begin(), vecPairs.end(), [](pair<int, int> lhs, pair<int, int> rhs)->bool {
		return lhs.second > rhs.second;
		});

	for (int i = 0; i < vecPairs.size(); ++i)
	{
		k -= vecPairs[i].second;

		answer++;

		if (k <= 0)
			break;
	}

	return answer;
}
