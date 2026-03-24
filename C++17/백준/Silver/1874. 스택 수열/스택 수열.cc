#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	int iN;
	cin >> iN;
	int iCurrent = 1;

	stack<int> s = {};
	queue<char> result = {};

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		bool CantCalc = { false };

		while (iNum >= iCurrent)
		{
			s.push(iCurrent);
			iCurrent++;
			result.push('+');
		}

		while (!s.empty() && iNum <= s.top())
		{
			if (false == s.empty())
			{
				int iFront = s.top();

				if(iFront == iNum)
					s.pop();
				else
				{
					CantCalc = true;
					break;
				}

			}

			result.push('-');
		}

		if (true == CantCalc)
		{
			cout << "NO";
			return 0;
		}
	}

	while (!result.empty())
	{
		cout << result.front() << "\n";
		result.pop();
	}

	return 0;
}