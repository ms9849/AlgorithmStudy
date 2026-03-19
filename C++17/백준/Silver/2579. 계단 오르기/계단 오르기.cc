#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iArray[10001] = {};
int iDp[10001] = {};

int main(void* pArg)
{
	int iN;
	
	cin >> iN; 

	for (int i = 1; i <= iN; ++i)
	{
		cin >> iArray[i];
	}
	
	iDp[1] = iArray[1];
	iDp[2] = iArray[2] + iArray[1];
	iDp[3] = max(iArray[1], iArray[2]) + iArray[3];
	for (int i = 4; i <= iN; ++i)
	{
		iDp[i] = max(iArray[i-1] + iDp[i - 3], iDp[i - 2]) + iArray[i];
	}

	cout << iDp[iN] << "\n";

	return 0;
}