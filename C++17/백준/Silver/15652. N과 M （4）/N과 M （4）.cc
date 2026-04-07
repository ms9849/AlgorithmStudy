#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> vecNums = {};
int iN, iK;

void Recursion(int iCurNum, int iCurLevel)
{
	if (iCurLevel == iK)
	{
		for (auto& iter : vecNums)
			cout << iter << " ";
		cout << "\n";
		
		return;
	}

	for (int i = 1; i <= iN; ++i)
	{
		if (i >= iCurNum)
		{
			vecNums.push_back(i);
			Recursion(i, iCurLevel + 1);
			vecNums.pop_back();
		}
	}
}

int main(void* pArg)
{
	cin >> iN >> iK;


	Recursion(1, 0);


	return 0;
}