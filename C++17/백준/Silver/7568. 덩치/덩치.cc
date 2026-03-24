#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	int iN;
	cin >> iN;

	vector<pair<int, int>> vecPeople = {};
	int iArray[51] = {};

	for (int i = 0; i < iN; ++i)
	{
		int iWeight, iHeight;
		cin >> iWeight >> iHeight;

		vecPeople.push_back(make_pair(iWeight, iHeight));
	}

	for (int i = 0; i < vecPeople.size(); ++i)
	{
		for (int j = 0; j < vecPeople.size(); ++j)
		{
			if ((i != j) &&
				(vecPeople[i].first < vecPeople[j].first) &&
				(vecPeople[i].second < vecPeople[j].second))
				iArray[i]++;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		cout << iArray[i] + 1 << " ";
	}

	return 0;
}