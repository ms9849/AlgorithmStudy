	#include <iostream>
	#include <vector>
	#include <map>
	#include <algorithm>
	#include <cmath>

	using namespace std;

	int main(void* pArg)
	{
		vector<int> vecNumbers = {};
		map<int, int> mapNumbers = {};
		vector<pair<int, int>> vecCountNumbers = {};

		double fSum = { 0.f };

		int iN{}, iSour{};
	
		cin >> iN;

		for (int i = 0; i < iN; ++i)
		{
			cin >> iSour;

			vecNumbers.emplace_back(iSour);
			mapNumbers[iSour]++;
			fSum += iSour;
		}

		sort(vecNumbers.begin(), vecNumbers.end(), [](int lhs, int rhs)->bool{
			//내림차순
			return lhs < rhs;
			});


		for (auto& iter : mapNumbers)
		{
			vecCountNumbers.emplace_back(make_pair(iter.first, iter.second));
		}

		sort(vecCountNumbers.begin(), vecCountNumbers.end(), [](pair<int,int> lhs, pair<int,int> rhs)->bool {
			//이 조건에 맞게 정렬해라..
			if (lhs.second == rhs.second)
				return lhs.first < rhs.first;
			else
				return lhs.second > rhs.second;
		});

		//1. 평균
		cout << floor(fSum / iN + 0.5f) << "\n";

		//2. 중앙값
		cout << vecNumbers[iN /2] << "\n";

		//3. 최빈값
		if (vecCountNumbers.size() == 1)
			cout << vecCountNumbers.begin()->first << "\n";

		else if (vecCountNumbers.begin()->second == (vecCountNumbers.begin() + 1)->second)
			cout << (vecCountNumbers.begin() + 1)->first << "\n";
		else
			cout << vecCountNumbers.begin()->first << "\n";
		//4. 범위
		cout << *(vecNumbers.end()-1) - *vecNumbers.begin() << "\n";


		return 0;
	}