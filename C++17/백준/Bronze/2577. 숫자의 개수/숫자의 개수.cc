#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void* pArg)
{
	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	string strResult = to_string(iA*iB*iC);

	int iResult[10] = { 0, };

	for (int i = 0; i < strResult.length(); ++i)
	{
		iResult[strResult[i] - '0']++;
	}

	for (int i = 0; i <= 9; ++i)
	{
		cout << iResult[i] << "\n";
	}

	return 0;
}