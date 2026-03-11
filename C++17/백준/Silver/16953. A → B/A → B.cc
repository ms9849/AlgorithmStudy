#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

void Find_Dest(long long iTemp, long long iDest, long long iCnt)
{
	if (iTemp == iDest)
	{
		pq.push(iCnt);
		return;
	}
	else if (iTemp > iDest)
		return;

	Find_Dest(iTemp * 10 + 1, iDest, iCnt + 1);
	Find_Dest(iTemp * 2, iDest, iCnt + 1);
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long iSour, iDest;

	cin >> iSour >> iDest;

	Find_Dest(iSour, iDest, 0);

	if (pq.empty())
		cout << -1 << "\n";

	else
		cout << pq.top() + 1;

	return 0;
}