#include <iostream>
using namespace std;

int dp[1001] = {};

int main(void* pArg)
{
	int iN;
	cin >> iN;

	//왜? 라고 하기엔.. 좀 그렇고
	//dp[i-1]에 일단 2x1 세워서 둠
	//dp[i-2]에 2x2 짜리 하나, 가로로 눕혀진 2x1 두개 있는 케이스.

	//직관적인 이해가 좀 필요하기도 하고.. 규칙 찾는게 어머같다.

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= iN; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[iN] << "\n";

	return 0;
}