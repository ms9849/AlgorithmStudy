#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iParent[1000001] = {};

int Find(int iStartNode)
{
	if (iStartNode != iParent[iStartNode])
		iParent[iStartNode] = Find(iParent[iStartNode]);

	return iParent[iStartNode];
}

void Union(int iLhs, int iRhs)
{
	int iLhsRoot = Find(iLhs);
	int iRhsRoot = Find(iRhs);

	if (iLhsRoot < iRhsRoot)
		iParent[iLhsRoot] = iRhsRoot;
	else
		iParent[iRhsRoot] = iLhsRoot;
}

int main(void* pArg)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//N은 숫자의 범위, M은 연산 갯수
	int iN{}, iM{};
	
	cin >> iN >> iM;

	for (int i = 0; i <= iN; ++i)
	{
		iParent[i] = i;
	}

	for (int i = 0; i < iM; ++i)
	{
		int iCalc, iSour, iDest;
		cin >> iCalc >> iSour >> iDest;

		if (0 == iCalc)
		{
			Union(iSour, iDest);
		}
		else if (1 == iCalc)
		{
			if (Find(iSour) == Find(iDest))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}