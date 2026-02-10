#include <iostream>
#include <map>
using namespace std;

int main(void* pArg)
{
	map<string, bool> Persons = {};
	int iN = {};
	int iResult = { 0 }; 
	Persons["ChongChong"] = { true };

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		string strSour, strDest;

		cin >> strSour >> strDest;

		if (Persons[strSour] || Persons[strDest])
		{
			Persons[strSour] = true;
			Persons[strDest] = true;
		}
	}


	for (auto& iter : Persons)
	{
		if (iter.second)
			iResult++;
	}

	cout << iResult;

	return 0;
}