#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	map<string, int> mapWant = {};
	map<string, int> mapCanBuy = {};
	int answer = 0; 

	int iLength = 0;

	for (int i = 0; i < want.size(); ++i)
	{
		mapWant[want[i]] = number[i];
		iLength += number[i];
	}

	for (int i = 0; i < iLength; ++i)
	{
		mapCanBuy[discount[i]] += 1;
	}

	for (int i = 0; i < discount.size() - iLength + 1; ++i)
	{
		if (i > 0)
		{
			mapCanBuy[discount[i - 1]] -= 1;
			mapCanBuy[discount[iLength + i - 1]] += 1;

		}

		bool isBuyable = { true };

		for (auto& iter : mapWant)
		{
			if (iter.second != mapCanBuy[iter.first])
			{
				isBuyable = false;
				continue;
			}
		}

		if (true == isBuyable)
			answer++;
	}


	return answer;
}
