#include <iostream>
using namespace std;

int iVisited[10] = { 0, };
int iArray[10] = { 0, };

void Recursion(int iNowNum, int iNowCnt, int iMaxNum, int iMaxCnt)
{
	if (iNowCnt != 0)
		iArray[iNowCnt] = iNowNum;

	if (iNowCnt == iMaxCnt)
	{
		for (int i = 1; i <= iMaxCnt; ++i)
			cout << iArray[i] << " ";

		cout << "\n";
		return;
	}
	

	for (int i = 1; i <= iMaxNum; ++i)
	{
		if (iVisited[i] == 0)
		{
			iVisited[i] = 1;
			Recursion(i, iNowCnt + 1, iMaxNum, iMaxCnt);
			iVisited[i] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int iMaxNum, iMaxCnt;

	cin >> iMaxNum >> iMaxCnt;

	Recursion(0, 0,iMaxNum, iMaxCnt);
	return 0;
}