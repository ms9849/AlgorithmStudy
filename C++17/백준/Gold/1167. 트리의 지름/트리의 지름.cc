#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vecEdges[100001] = {};
int iVisited[100001] = { 0, };
int iLongestNode = { };
int iMaxValue = { };


void DFS(int iNode, int iCost)
{
	if (iVisited[iNode])
		return;

	if (iCost > iMaxValue)
	{
		iMaxValue = iCost;
		iLongestNode = iNode;
	}

	for (auto& iter : vecEdges[iNode])
	{
		iVisited[iNode] = 1;
		DFS(iter.first, iCost + iter.second);
		iVisited[iNode] = 0;
	}
}

int main(void* pArg)
{
	int iN;

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iStart;
		cin >> iStart;

		while (1)
		{
			int iDest, iCost;

			cin >> iDest;

			if (iDest == -1)
				break;

			cin >> iCost; 
			//값도 이렇게 해서 넣어줘.
			vecEdges[iStart].push_back(make_pair(iDest, iCost));
		}
	}

	DFS(1, 0);

	//초기화.
	
	iMaxValue = 0;
	for (int i = 0; i <= 100000; ++i)
	{
		iVisited[i] = 0;
	}

	DFS(iLongestNode, 0); 

	cout << iMaxValue << "\n";

	return 0;
}