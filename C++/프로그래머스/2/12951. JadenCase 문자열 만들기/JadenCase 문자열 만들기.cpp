#include <string>
#include <vector>

using namespace std;

string solution(string s) {

	string answer = "";
	bool isFirstCase = { true };

	for (int i = 0; i < s.length(); ++i)
	{
		if (i == 0 || s[i - 1] == ' ')
			isFirstCase = true;
		else
			isFirstCase = false;

		if (true == isFirstCase)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				answer += s[i] + 'A' - 'a';
			}
			else
				answer += s[i];
		}
		else
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				answer += s[i] - ('A' - 'a');
			}
			else
				answer += s[i];
		}
	}


	return answer;
}