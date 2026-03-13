#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	long long iN;

	cin >> iN;

	int iMax = 0;

	for (long long i = 1; i < iN; ++i)
	{
		long long iSum = i * (i + 1) / 2;

		if (iSum < iN)
		{
			if(iN - iSum > i)
				iMax = i;
		}
		else
			break;
	}
	
	cout << iMax + 1 << "\n";

	return 0;
}