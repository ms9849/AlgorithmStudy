#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> DigitChange(string s) {
	vector<int> vecResult = {};
	vecResult.push_back(0);
	vecResult.push_back(0);

	while (s != "1")
	{
		string strResult = {};

		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '1')
				strResult += '1';
			else
				vecResult[1] += 1;
		}

		int iLength = strResult.length();

		stack<char> st = {};
		string strConvert = {};
		while (1)
		{
			if (iLength >= 2)
			{
				st.push((iLength % 2) + '0');
			}
			else
			{
				st.push(iLength + '0');
				break;
			}

			iLength /= 2;
		}

		s = {};
		while (!st.empty())
		{
			s += st.top();
			st.pop();
		}
		vecResult[0] += 1;
	}

	return vecResult;
}

vector<int> solution(string s) {
	vector<int> answer = DigitChange(s);
	return answer;
}
