#include <string>
#include <vector>

using namespace std;

int iDp[100001] = {};

int solution(int n) {

	iDp[1] = 1;
	iDp[0] = 0;
	for (int i = 2; i <= n; ++i)
	{
		iDp[i] =  (iDp[i - 1] + iDp[i - 2]) % 1234567;
	}

	return iDp[n];
}
