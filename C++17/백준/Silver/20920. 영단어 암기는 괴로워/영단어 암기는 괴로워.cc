#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void* pARg)
{
	//빈도수
	map<string, int> ct;
	vector<pair<string, int>> vec = {};

	string strWord;
	int iN, iK;

	cin >> iN >> iK;

	for (int i = 0; i < iN; ++i)
	{
		cin >> strWord;

		if(strWord.length() >= iK)
			ct[strWord]++;
	}


	for (auto& iter : ct)
	{
		vec.push_back(make_pair(iter.first, iter.second));
	}

	sort(vec.begin(), vec.end(), [](pair<string, int>& lhs, pair<string, int>& rhs)->bool {

		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;

		if (lhs.first.length() != rhs.first.length())
			return lhs.first.length() > rhs.first.length();

		if (lhs.first != rhs.first)
			return lhs.first < rhs.first;
		});

	for (auto& iter : vec)
	{
		cout << iter.first << "\n";
	}

	return 0;
}