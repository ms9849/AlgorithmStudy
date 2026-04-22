#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	 
	string strTemp = "";
	vector<int> vecNums = {};

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			vecNums.push_back(stoi(strTemp));
			strTemp = "";
		}
		else
		{
			strTemp += s[i];
		}
	}

	vecNums.push_back(stoi(strTemp));

	sort(vecNums.begin(), vecNums.end());

	answer += to_string(vecNums[0]);
	answer += " ";
	answer += to_string(vecNums[vecNums.size() - 1]);

	return answer;
}
