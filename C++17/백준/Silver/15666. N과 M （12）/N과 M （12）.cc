#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN, iM;

vector<int> vecNums = {};

vector<int> vecResults = {};

void Recursion(int iCurNumber, int iCount)
{
	if (iCount == iM)
	{
		for (auto& iter : vecResults)
			cout << iter << " ";

		cout << "\n";

		return;
	}

	for (auto& iter : vecNums)
	{
		int iMin = vecResults.empty() ? iCurNumber : vecResults.back();
		if (iter >= iMin)
		{
			vecResults.push_back(iter);
			Recursion(iCurNumber, iCount + 1);
			vecResults.pop_back();
		}
	}
}

int main(void* pArg)
{
	bool isAlreadyIn = { false };

	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		for (auto& iter : vecNums)
		{
			if (iSour == iter)
				isAlreadyIn = true;
		}

		if(false == isAlreadyIn)
			vecNums.push_back(iSour);

		isAlreadyIn = false;
	}

	sort(vecNums.begin(), vecNums.end());

	Recursion(0, 0);


	return 0;
}