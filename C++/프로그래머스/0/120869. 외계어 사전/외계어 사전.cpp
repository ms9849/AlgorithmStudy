#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
	
	for (auto& strWord : dic)
	{
		int Word[26] = {};

		for (auto& iter : spell)
			Word[iter[0] - 'a']++;

		for (int i = 0; i < strWord.size(); ++i)
		{
			Word[strWord[i] - 'a']--;
		}

		bool isAlien = true;
		for (int i = 0; i < 26; ++i)
		{
			if (Word[i] != 0)
				isAlien = false;
		}

		if (true == isAlien)
			return 1;
	}

	return 2;
}
