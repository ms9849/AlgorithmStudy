#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

string CreateNextString(int iIdx, string& strTemp)
{
	string Front = {};
	string Back = {};

	for (int i = iIdx; i< strTemp.length(); i++)
	{
		Front += strTemp[i];
	}

	for (int j = 0; j < iIdx; ++j)
	{
		Back += strTemp[j];
	}
	
	string str = Front + Back;
	return str;
}

int solution(string s) {
	int answer = 0;
	int iCount = s.length();

	for (int i = 0; i < iCount; ++i)
	{
		int iIdx = 0;
		bool isCorrect = { true };
		stack<char> st = {};
		string strTemp = CreateNextString(i, s);

		while (iIdx < strTemp.length())
		{
			switch (strTemp[iIdx])
			{
			case '[':
			case '(':
			case '{':
				st.push(strTemp[iIdx]);
				break;

			case ')':
				if (st.empty() || st.top() != '(')
					isCorrect = false;
				else
					st.pop();
				break;
			case '}':
				if (st.empty() || st.top() != '{')
					isCorrect = false;
				else
					st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[')
					isCorrect = false;
				else
					st.pop();
				break;
			}

			if (false == isCorrect)
				break;

			iIdx++;
		}

		if (true == isCorrect && st.empty())
			answer++;
	}

	return answer; 
}
