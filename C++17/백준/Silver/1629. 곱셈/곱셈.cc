#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

long long Multi(long long iA, long long iB, long long iC)
{
	if (iB == 1)
		return iA % iC;

	int iResult = Multi(iA, iB / 2, iC);

	if (iB % 2 == 1)
		return iA % iC * iResult % iC * iResult % iC;
	else
		return iResult % iC * iResult % iC;
}

int main(void* pArg)
{
	long long iA, iB, iC;

	cin >> iA >> iB >> iC;

	long long iResult = Multi(iA, iB, iC);

	cout << iResult << "\n";

	return 0;
}