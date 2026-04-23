#include <string>
#include <vector>
#include <queue>

using namespace std;

long long iDp[2001] = {};

long long solution(int n) {

	iDp[1] = 1;
	iDp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		iDp[i] = ( iDp[i - 1] + iDp[i - 2] ) % 1234567;
	}

	return iDp[n];
}
