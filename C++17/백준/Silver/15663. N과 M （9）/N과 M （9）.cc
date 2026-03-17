#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecNums = {};
int iMaxCount[10001] = {};
int iVisitCount[10001] = {};
vector<int> vecVisited = {};

int iN, iM;

void Search(int iCount)
{
	if (iCount == iM)
	{
		for (int i = 0; i < vecVisited.size();++i)
		{
			cout << vecVisited[i] << " ";
		}
		cout << "\n";

		return;
	}

	int iMax = vecNums.size();

	for (int i = 0; i < iMax; ++i)
	{
		if (iVisitCount[vecNums[i]] < iMaxCount[vecNums[i]])
		{
			iVisitCount[vecNums[i]]++;
			iCount++;
			vecVisited.push_back(vecNums[i]);

			Search(iCount);

			iCount--;
			iVisitCount[vecNums[i]]--;
			vecVisited.pop_back();
		}
	}
}


int main(void* pArg)
{
	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		if(iMaxCount[iSour] == 0)
			vecNums.push_back(iSour);
		iMaxCount[iSour]++;
	}

	sort(vecNums.begin(), vecNums.end());

	Search(0);

	return 0;
}