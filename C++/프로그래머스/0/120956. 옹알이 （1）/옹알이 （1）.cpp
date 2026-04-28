#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	vector<string> CanBable = {
		"aya",
		"ye",
		"woo",
		"ma"
	};

	for (auto& Word : babbling)
	{
		bool OnlyBabble = true; 

		for (int i = 0; i < Word.length(); ++i)
		{
			int iSameLength = 0;
			int iDiffCount = 0;
	
			for (auto& Babble : CanBable)
			{
				for (int j = 0; j < Babble.length(); ++j)
				{
					if (i + j > Word.length() - 1 || Babble[j] != Word[i + j])
					{
						iDiffCount++;
						break;
					}

					iSameLength = Babble.length();
				}
			}

			if (iDiffCount != 4)
			{
				i += (iSameLength -1);
			}
			else
			{
				OnlyBabble = false;
				break;
			}
		}

		if (true == OnlyBabble)
			answer++;
	}

	return answer;
}