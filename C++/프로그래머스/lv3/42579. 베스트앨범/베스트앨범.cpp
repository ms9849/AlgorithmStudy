#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	//정렬할떄 필요한거 -> 장르 이름, 곡 고유 플레이 횟수, 곡 인덱스
	map<string, int> mapGenrePlayed = {};

	//재생수, idx
	map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>>
		mapDatas = {};

	vector<int> answer;

	int iIdx = 0;

	for (auto& iter : genres)
	{
		mapGenrePlayed[iter] += plays[iIdx];
		mapDatas[iter].push({plays[iIdx], iIdx});
		iIdx++;
	}

	vector<pair<string, int>> vecGenreSorted = {};
	for (auto& iter : mapGenrePlayed)
	{
		vecGenreSorted.push_back({ iter.first, iter.second });
	}

	sort(vecGenreSorted.begin(), vecGenreSorted.end(), [](pair<string, int> lhs, pair<string, int> rhs)->bool {
		return lhs.second > rhs.second;
	});

	for (auto& iter : vecGenreSorted)
	{
		int iCount = 0;
		vector<pair<int, int>> vecTemp = {};


		while (!mapDatas[iter.first].empty() && iCount < 2)
		{
			pair<int, int> IdxData = mapDatas[iter.first].top();
			vecTemp.push_back(IdxData);
			mapDatas[iter.first].pop();
		}

		sort(vecTemp.begin(), vecTemp.end(), [](pair<int,int> lhs, pair<int,int> rhs)->bool {
			if (lhs.first == rhs.first)
				return lhs.second < rhs.second;
			else
				return lhs.first > rhs.first;
		});


		while(iCount < 2 && iCount < vecTemp.size())
		{
			answer.push_back( vecTemp[iCount].second );
			iCount++;
		}
	}

	return answer;
}


