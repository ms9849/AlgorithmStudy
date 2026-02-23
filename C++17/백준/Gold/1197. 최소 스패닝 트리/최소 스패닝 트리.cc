#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iV{}, iE{};

int iParent[10001] = { 0, };

int iCnt = 0;

vector<pair<pair<int, int>, int>> vecEdges = {};

int Find(int iStartNode)
{
	if (iStartNode != iParent[iStartNode])
		iParent[iStartNode] = Find(iParent[iStartNode]);

	return iParent[iStartNode];
}

bool Union(int iLhs, int iRhs)
{
	int iLhsParent = Find(iLhs);
	int iRhsParent = Find(iRhs);

	if (iLhsParent > iRhsParent)
		iParent[iLhsParent] = iRhsParent;
	else if (iLhsParent < iRhsParent)
		iParent[iRhsParent] = iLhsParent;
	else
		return false;

	return true;
}

int main(void* pArg)
{
	cin >> iV >> iE;

	int iMinCost = 0;

	for (int i = 1; i <= iV;++i)
	{
		iParent[i] = i;
	}

	for (int i = 0; i < iE; ++i)
	{
		int iSour, iDest, iCost;
		cin >> iSour >> iDest >> iCost;

		vecEdges.push_back(make_pair(make_pair(iSour, iDest), iCost));
	}
	
	//비용순 정렬
	sort(vecEdges.begin(), vecEdges.end(), [](pair<pair<int, int>, int> lhs, pair<pair<int, int>, int> rhs)->bool {
		return lhs.second < rhs.second;
		});


	for (auto iter : vecEdges)
	{
		if (iCnt == iV - 1)
			break;

		if (Union(iter.first.first, iter.first.second))
		{
			iMinCost += iter.second;
			iCnt++;
		}
	}
	

	cout << iMinCost;

	return 0;
}