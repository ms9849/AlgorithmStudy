#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include "math.h"

using namespace std;

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<long long, long long>> vecNums = {};
	int iN;
	cin >> iN;

	for(int i=0; i<iN; ++i)
	{
		long long iX, iY;
		cin >> iX >> iY;

		vecNums.push_back({ iX, iY });
	}
	
	//신발끈 공식
	long double iResult = 0;

	for (int i = 0; i < iN - 1; ++i)
	{
		iResult += vecNums[i].first * vecNums[i + 1].second;
	}
	iResult += vecNums[iN - 1].first * vecNums[0].second;


	for (int i = 0; i < iN - 1; ++i)
	{
		iResult -= vecNums[i + 1].first * vecNums[i].second;
	}
	iResult -= vecNums[0].first * vecNums[iN - 1].second;

	cout << fixed << setprecision(1);
	cout << round(abs(iResult) * 0.5f * 100) / 100.0;

	return 0;
}