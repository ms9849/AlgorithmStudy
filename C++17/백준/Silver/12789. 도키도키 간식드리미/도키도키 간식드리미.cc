#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iN;
vector<int> vecNums = {}; 
stack<int> stackNums = {};

int main(void* pArg)
{
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		vecNums.push_back(iSour);
	}

	int iTarget = 1;
	int iCount = 0;

	while (!vecNums.empty())
	{
		if (vecNums.front() == iTarget)
		{
			iTarget++;
			iCount++;
			vecNums.erase(vecNums.begin(), vecNums.begin() + 1);
		}
		else if (vecNums.front() != iTarget)
		{
			if (!stackNums.empty() && stackNums.top() == iTarget)
			{
				iTarget++;
				iCount++;
				stackNums.pop();
			}
			else
			{
				stackNums.push(*vecNums.begin());
				vecNums.erase(vecNums.begin(), vecNums.begin() + 1);
			}
		}
	}

	while (!stackNums.empty() && stackNums.top() == iTarget)
	{
		stackNums.pop();
		iTarget++;
		iCount++;
	}

	if (iCount != iN)
		cout << "Sad\n";
	else
		cout << "Nice\n";

	return 0;
}
