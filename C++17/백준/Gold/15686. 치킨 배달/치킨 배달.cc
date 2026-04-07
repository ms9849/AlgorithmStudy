#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iBoard[51][51] = {};
int iN{}, iM{};

/*
* 집마다 모든 치킨집과의 거리를 비교해두긴 해야함.
* 
* 2500 * 13인데, 구해두는것 자체는 그리 어렵지 않아보인다.
* 근데 이게 맞나. idx 순으로 하면 될 것 같긴한데..
*/

vector<pair<int, int>> vecChickens = {};
vector<pair<int, int>> vecHouses = {};

int iMinValue = 987654321;

void Find_MinChicken(int iNum, int iStartIdx)
{
	if (iNum == iM)
	{
		int iChickenDist = 0;

		for (auto& HouseLoc : vecHouses)
		{
			int iMin = 987654321;
			for (auto& ChickenLoc : vecChickens)
			{
				if (iBoard[ChickenLoc.first][ChickenLoc.second] == 3)
				{
					int iDist = abs(HouseLoc.first - ChickenLoc.first) + abs(HouseLoc.second - ChickenLoc.second);
					if (iMin > iDist)
						iMin = iDist;
				}
			}

			iChickenDist += iMin;
		}

		if (iChickenDist < iMinValue)
			iMinValue = iChickenDist;
		
		return;
	}

	int iSize = vecChickens.size();

	for (int i = iStartIdx; i < iSize; ++i)
	{
		if (iBoard[vecChickens[i].first][vecChickens[i].second] == 2)
		{
			iBoard[vecChickens[i].first][vecChickens[i].second] = 3;

			Find_MinChicken(iNum + 1, i + 1);

			iBoard[vecChickens[i].first][vecChickens[i].second] = 2;
		}

	}

}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			cin >> iBoard[i][j];

			if (iBoard[i][j] == 2)
				vecChickens.push_back({ i,j });

			if (iBoard[i][j] == 1)
				vecHouses.push_back({ i,j });
		}
	}

	Find_MinChicken(0, 0);

	cout << iMinValue; 

	return 0;
}