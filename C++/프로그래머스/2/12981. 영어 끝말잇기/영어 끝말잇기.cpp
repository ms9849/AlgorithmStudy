#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
vector<int> solution(int n, vector<string> words) {
	//몇번째 사람이 탈락하는지, 몇번쨰 턴에서?
	vector<int> answer = { 0,0 };
	string strPreWord = {};
	map<string, int> mapWordCounter = {};

	int iCount = 1;

	for(auto& iter : words)
	{
		if (mapWordCounter[words[iCount-1]] != 0 || 
			(iCount != 1 && strPreWord[strPreWord.size()-1] != iter[0]))
		{
			if (iCount % n == 0)
			{
				answer[0] = n;
				answer[1] = iCount / n;
			}
			else
			{
				answer[0] = iCount % n;
				answer[1] = iCount / n + 1;
			}


			break;
		}

		mapWordCounter[words[iCount-1]] = 1;
		strPreWord = words[iCount-1];

		iCount++;
	}

	return answer;
}



