#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iV, iE;

//크루스칼은.. 유니온 파인드 연산을 메인으로 하지?..
//간선의 시작점과 도착점을 Union 연산하여 다른 그룹이라면 간선 ++ 하고 비용도 더하기.
//이렇게 채워진 간선들이 iV-1개라면.. 끝냄.

int iParent[10001] = { 0, };
int iSum = 0;
int iCount = 0;

vector<pair<pair<int, int>, int>>  vecEdges = {};

int Find(int iNum)
{
	if (iParent[iNum] != iNum)
		iParent[iNum] = Find(iParent[iNum]);

	return iParent[iNum];
}

bool Union(int iLhs, int iRhs)
{
	int iLhsParent = Find(iLhs);
	int iRhsParent = Find(iRhs);

	if (iLhsParent == iRhsParent)
		return false;
	else if (iLhsParent < iRhsParent)
		iParent[iRhsParent] = iLhsParent;
	else if (iLhsParent > iRhsParent)
		iParent[iLhsParent] = iRhsParent;

	return true;
}

int main(void* pArg)
{
	cin >> iV >> iE;

	for (int i = 0; i <= 10000; ++i)
		iParent[i] = i;

	for (int i = 0; i < iE; ++i)
	{
		int iSour, iDest, iCost;

		cin >> iSour >> iDest >> iCost;
		
		vecEdges.emplace_back(make_pair(make_pair(iSour, iDest), iCost));
	}

	sort(vecEdges.begin(), vecEdges.end(), 
		[](pair<pair<int, int>, int> Lhs, pair<pair<int, int>, int> Rhs)->bool {
			return Lhs.second < Rhs.second;
		});

	for (auto& iter : vecEdges)
	{
		bool bResult = Union(iter.first.first, iter.first.second);

		if (bResult == true)
		{
			++iCount;
			iSum += iter.second;
		}
	}

	cout << iSum << "\n";

	return 0;
}