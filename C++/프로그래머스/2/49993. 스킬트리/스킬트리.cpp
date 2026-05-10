#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	
	int iAnswer = 0;
	int iArray[30] = {};

	for (int i = 0; i < skill.length(); ++i)
	{
		// 몇번쨰로 나온 스킬인가?
		// 0이라면 나온적이 없는 스킬이니까,
		// 계산에서 제외함.
		iArray[skill[i] - 'A'] = i+1;
	}

	for (auto& iter : skill_trees)
	{
		bool isEnable = { true };
		int iCurIndex = 1;

		for (int i = 0; i < iter.length(); ++i)
		{
			if (iArray[iter[i] - 'A'] == 0)
				continue;
			else
			{
				if (iArray[iter[i] - 'A'] != iCurIndex++)
					isEnable = false;
			}
		}

		if (true == isEnable)
			iAnswer++;
	}

	return iAnswer;
}