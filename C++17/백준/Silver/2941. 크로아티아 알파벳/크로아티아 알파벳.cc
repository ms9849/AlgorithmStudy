#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int iCnt(0), iLength(0);
	char szStr[120];
	// c,d,l,n,s,z
	// =,-
	cin >> szStr;
	iLength = strlen(szStr);

	for (int i = 0; i < iLength; ++i)
	{
		if ('c' == szStr[i] && '=' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('c' == szStr[i] && '-' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('d' == szStr[i] && 'z' == szStr[i + 1] && '=' == szStr[i + 2])
		{
			iCnt++;
			i+=2;
			continue;
		}
		else if ('d' == szStr[i] && '-' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('l' == szStr[i] && 'j' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('n' == szStr[i] && 'j' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('s' == szStr[i] && '=' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		else if ('z' == szStr[i] && '=' == szStr[i + 1])
		{
			iCnt++;
			i++;
			continue;
		}
		iCnt++;
	}
	cout << iCnt << endl;
	return 0;
}