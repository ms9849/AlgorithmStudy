#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> SiteHash = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iN, iM;

	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		string iSour, iDest;
		cin >> iSour >> iDest;

		SiteHash.emplace(iSour, iDest);
	}

	for (int i = 0; i < iM; ++i)
	{
		string iSour;
		cin >> iSour;

		cout << SiteHash[iSour] << "\n";
	}

	return 0;
}