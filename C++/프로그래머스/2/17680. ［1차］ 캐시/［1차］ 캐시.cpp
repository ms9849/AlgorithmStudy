#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {

	for (int i = 0; i < cities.size(); ++i)
	{
		for (int j = 0; j < cities[i].length(); ++j)
		{
			cities[i][j] = tolower(cities[i][j]);
		}
	}

	map<string, int> mapCache = {};
	int iCostSum = {};
	int iMaxCacheSize = cacheSize;

	for (int i = 0; i < cities.size(); ++i)
	{
		bool isCacheHit = { false };

		if (mapCache.end() != mapCache.find(cities[i]))
		{
			isCacheHit = true;
			mapCache[cities[i]] = i;
		}
		else
		{
			//캐시 등록
			isCacheHit = false;

			if (iMaxCacheSize != 0)
			{
				if (mapCache.size() == iMaxCacheSize)
				{
					string strLRU = {};
					int iMin = 2000000;
					//LRU는 오랫동안 참조되지 않은 녀석을 지우니까..
					for (auto& iter : mapCache)
					{
						if (iter.second < iMin)
						{
							iMin = iter.second;
							strLRU = iter.first;
						}
					}

					mapCache.erase(strLRU);
				}

				mapCache.emplace(cities[i], i);
			}

		}


		//캐시 히트에 따라 작업량 처리.
		if (true == isCacheHit)
			iCostSum += 1;
		else
			iCostSum += 5;
	}

	return iCostSum;
}