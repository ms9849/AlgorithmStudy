#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int iAlphabet[30][200001] = {};

int main(void* pArg)
{
	ios::sync_with_stdio();
	cin.tie(0);

	int iN;
	string strSour;

	cin >> strSour;
	int iLength = strSour.length();

	for (int i = 0; i < iLength; ++i)
	{
		for (int j = 0; j <= 'z'-'a'; ++j)
		{
			if(i > 0)
				iAlphabet[j][i] = iAlphabet[j][i - 1] + ('a' + j == strSour[i] ? 1 : 0);
			else if(i == 0)
				iAlphabet[j][i] = ('a' + j == strSour[i] ? 1 : 0);
		}
	}

	cin >> iN;

	char szTemp;
	int iStart, iEnd;

	for (int i = 0; i < iN; ++i)
	{
		cin >> szTemp >> iStart >> iEnd;

		cout << iAlphabet[szTemp - 'a'][iEnd] - iAlphabet[szTemp - 'a'][iStart] + (szTemp == strSour[iStart] ? 1 : 0) << "\n";
	}

	return 0;
}