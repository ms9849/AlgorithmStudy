#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// K개를 더해서 N까지 도달한 상태.
long long iDp[201][201] = {};

int main(void* pArg)
{
	int iN, iK;

	cin >> iN >> iK;

	//1개를 써서 N까지는 다 도달이 가능하지.
	for (int i = 0; i <= iN; ++i)
		iDp[1][i] = 1 % 1000000000;

	for (int i = 2; i <= iK; ++i)
	{
		for (int j = 0; j <= iN; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				iDp[i][j] += iDp[i-1][j-k] % 1000000000;
			}
		}
	}

	cout << iDp[iK][iN] % 1000000000;

	return 0;
}