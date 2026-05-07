#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void Split_CarInfo(string strInfo, string* pTime, string* pNum, string* pIsIn)
{
	int iCount = 0;
	*pTime = {};
	*pNum = {};
	*pIsIn = {};

	for (auto& iter : strInfo)
	{
		if (iter == ' ')
		{
			iCount++;
			continue;
		}

		if (0 == iCount)
			*pTime += iter;
		else if (1 == iCount)
			*pNum += iter;
		else if (2 == iCount)
			*pIsIn += iter;
	}
}

// 첫 원소를 고르고, 마지막꺼 고른게 중요한거 아닌가?..
void Split_Time(string strStart, string* pFront, string* pBack)
{
	bool isFront = true;
	*pFront = {};
	*pBack = {};

	for (auto& iter : strStart)
	{
		if (iter == ':')
		{
			isFront = false;
			continue;
		}

		if (true == isFront)
			*pFront += iter;
		else
			*pBack += iter;
	}
}

int CalcTime(string strStart, string strEnd)
{
	string strStartFront = {};
	string strStartBack = {};
	string strEndFront = {};
	string strEndBack = {};

	Split_Time(strStart, &strStartFront, &strStartBack);
	Split_Time(strEnd, &strEndFront, &strEndBack);

	int iHour = stoi(strEndFront) - stoi(strStartFront);
	int iMinute = stoi(strEndBack) - stoi(strStartBack);

	if (iMinute < 0)
	{
		iMinute += 60;
		iHour -= 1;
	}

	return iHour * 60 + iMinute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	// 차량 번호, 비용 순
	vector<int> answer;
	map<string, int> mapDailyReports = {};
	map<string, int> mapCosts = {};
	map<string, string> mapRecords = {};

	for (auto& iter : records)
	{
		string strTime = {}, strCarNumber = {}, strIsIn = {};

		Split_CarInfo(iter, &strTime, &strCarNumber, &strIsIn);

		if (strIsIn == "IN")
		{
			mapRecords.emplace(strCarNumber, strTime);
		}
		else if (strIsIn == "OUT")
		{
			auto iter = mapRecords.find(strCarNumber);

			//시작한 시간이 들어가있겠지?
			int iTime = CalcTime(iter->second, strTime);
			int iCarNumber = stoi(iter->first);
			mapRecords.erase(iter);

			mapDailyReports[to_string(iCarNumber)] += iTime;
		}
	}

	for (auto& iter : mapRecords)
	{
		int iTime = CalcTime(iter.second, "23:59");
		int iCarNumber = stoi(iter.first);

		mapDailyReports[to_string(iCarNumber)] += iTime;
	}

	for(auto& iter : mapDailyReports)
	{
		//시작한 시간이 들어가있겠지?
		int iTime = iter.second;
		int iCarNumber = stoi(iter.first);

		if (iTime <= fees[0])
		{
			mapCosts[to_string(iCarNumber)] = fees[1];
		}
		else
		{
			int iCost = {};

			if ((iTime - fees[0]) % fees[2] != 0)
				iCost = fees[1] + (((iTime - fees[0] + fees[2]) / fees[2]) * fees[3]);
			else
				iCost = fees[1] + (((iTime - fees[0]) / fees[2]) * fees[3]);

			mapCosts[to_string(iCarNumber)] = iCost;
		}
	}

	vector<pair<int, int>> vecCosts = {};

	for (auto& iter : mapCosts)
	{
		vecCosts.push_back({ stoi(iter.first), iter.second });
	}

	sort(vecCosts.begin(), vecCosts.end(), [](pair<int, int> lhs, pair<int, int> rhs)->bool {
		return lhs.first < rhs.first;
	});

	for (auto& iter : vecCosts)
	{
		answer.push_back(iter.second);
	}

	return answer;
}