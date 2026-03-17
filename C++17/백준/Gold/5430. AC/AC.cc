#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void* pArg)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int iT;

	cin >> iT;

	while (iT > 0)
	{
		deque<int> dq = {};
		string strCommand = {};
		string strNum = {};

		int iNumCount = {};

		cin >> strCommand;
		cin >> iNumCount;
		cin >> strNum;

		int iLength = strNum.length();
		string strNumStack = {};

		if (iNumCount != 0)
		{
			for (int i = 0; i < iLength; ++i)
			{
				char cPart = strNum[i];

				if (cPart != '[' && cPart != ']' && cPart != ',')
				{
					strNumStack += cPart;
				}
				else if (cPart == ',' || cPart == ']')
				{
					dq.push_back(stoi(strNumStack));
					strNumStack = "";
				}
			}
		}

		iLength = strCommand.length();
		bool isRotate = { false };


		bool isError = { false };
		for (int i = 0; i < iLength; ++i)
		{
			char cCmd = strCommand[i]; 

			switch (cCmd)
			{
			case 'R':
				isRotate = !isRotate;
				break;

			case 'D':

				if (dq.empty())
				{
					isError = true;
					break;
				}


				if (false == isRotate)
				{
					dq.pop_front();
				}

				else if (true == isRotate)
				{
					dq.pop_back();
				}

				break;

			default:
				break;
			}
		}


		if (true == isError)
		{
			cout << "error\n";
		}
		else
		{
			cout << '[';
			if (true == isRotate)
			{
				for (int i = dq.size() - 1; i >= 0; --i)
				{
					cout << dq[i];

					if (i != 0)
						cout << ',';
				}
			}
			else
			{
				for (int i = 0; i < dq.size(); ++i)
				{
					cout << dq[i];

					if (i != dq.size() - 1)
						cout << ',';
				}
			}
			cout << "]\n";
		}

		iT--;
	}
	return 0;
}