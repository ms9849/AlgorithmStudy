#include <iostream>
#include <stack>

using namespace std;

int main(void* pArg)
{
	stack<char> s = {};
	string strCmd = {};
	cin >> strCmd;

	int iLength = strCmd.length();

	for (int i = 0; i <= iLength; ++i)
	{
		if (strCmd[i] >= 'A' && strCmd[i] <= 'Z')
		{
			cout << strCmd[i];
		}

		else if (strCmd[i] == '(')
		{
			s.push(strCmd[i]);
		}

		else if (strCmd[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (strCmd[i] == '*' || strCmd[i] == '/')
		{
			while (!s.empty() && (s.top() == '*' || s.top() == '/')
				&& s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(strCmd[i]);
		}
		else if (strCmd[i] == '+' || strCmd[i] == '-')
		{
			while (!s.empty() 
				&& s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(strCmd[i]);
		}
	}

	while (!s.empty())
	{
		if(s.top() != '(')
			cout << s.top();
		s.pop();
	}

	return 0;
}