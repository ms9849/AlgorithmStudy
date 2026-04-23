#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> st = {};

	bool isCorrect = { true };

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
		{
			st.push('(');
		}
		else if (s[i] == ')')
		{
			if (st.empty())
			{
				isCorrect = false;
				return isCorrect;
			}
			else
			{
				st.pop();
			}
		}
	}

	if (st.empty())
		isCorrect = true;
	else
		isCorrect = false;

	return isCorrect;
}