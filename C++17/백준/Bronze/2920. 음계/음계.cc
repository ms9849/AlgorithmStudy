#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	vector<int> vecNums = {};

	for (int i = 0; i < 8; ++i)
	{
		int iSour;
		cin >> iSour; 
		vecNums.push_back(iSour);
	}

	bool isAscending = { false }; 
	bool isDescending = { false };
	int iSour = vecNums[0];
	
	for (int i = 1; i < 8; ++i)
	{
		if (vecNums[i] > iSour)
		{
			isAscending = true;
		}
		else if (vecNums[i] < iSour)
		{
			isDescending = true;
		}

		iSour = vecNums[i];
	}

	if (true == isAscending && true == isDescending)
	{
		cout << "mixed";
	}
	else if (true == isAscending)
	{
		cout << "ascending";
	}
	else
		cout << "descending";
	return 0;
}