#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> mapIndex = {};
	int iCount = 1;

	for (int i = 1; i <= 26; ++i)
	{
		mapIndex.emplace(string(1, 'A' + (i-1)), i);
		iCount++;
	}

	for (int i = 0; i < msg.length(); ++i)
	{
		int iCycleCount = 0;
		int iCurIdx = i;
		string strPart = string(1, msg[iCurIdx]);
		string strLastSuccess = {};

		while(mapIndex[strPart] != 0)
		{
			iCurIdx++;

			strLastSuccess = strPart;
			strPart += string(1, msg[iCurIdx]);

			iCycleCount++;
		}

		answer.push_back(mapIndex[strLastSuccess]);

		mapIndex[string(strPart)] = iCount;
		iCount++;

		i += (iCycleCount - 1);
	}


	return answer;
}