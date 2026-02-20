#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iArray[100001] = {};
int iPrefixSum[100001] = {};
int iN, iM;

int main(void* pArg)
{
	//아오 입출력시치
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
	{
		int iSour;
		cin >> iSour;
		iArray[i] = iSour;

		if (i >= 2)
			iPrefixSum[i] = iPrefixSum[i - 1] + iSour;
		else if (i == 1)
			iPrefixSum[i] = iSour;
	}

	for (int i = 0; i < iM; ++i)
	{
		int iSour, iDest;
		cin >> iSour >> iDest;
		
		cout << iPrefixSum[iDest] - iPrefixSum[iSour] + iArray[iSour] << "\n";
	}

	return 0;
}