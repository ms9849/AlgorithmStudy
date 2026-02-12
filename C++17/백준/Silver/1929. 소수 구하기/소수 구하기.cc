#include <iostream>
using namespace std;

int iArray[1000001] = { 0, };

int main(void* pArg)
{
	int N, M;
	iArray[1] = 1;

	cin >> N >> M;

	for (int i = 2; i <= M; ++i)
	{
		int iCount = 2;
		int iSour = i;
		while (iSour * iCount <= M)
		{
			// 1이라면, 소수가 아님
			iArray[iSour * iCount] = 1;
			iCount++;
		}
	}

	for (int i = N; i <= M; ++i)
	{
		if(0 == iArray[i])
			cout << i << "\n";
	}
	
	return 0;
}