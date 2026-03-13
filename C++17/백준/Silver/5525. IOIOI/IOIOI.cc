#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

string str;

char TargetChars[2] = { 'I', 'O' };
int iCurIdx = 0;

int main(void* pArg)
{
	int iN, iM;
	int iCount = 0;

	cin >> iN >> iM >> str;

	char TargetChar = TargetChars[iCurIdx];

	int iGroup = 0;

	for (int i = 0; i < iM; ++i)
	{

		if (str[i] == TargetChar)
		{
			iGroup++;

			iCurIdx = 1 - iCurIdx;
			TargetChar = TargetChars[iCurIdx];
		}
		else
		{
			if (str[i] == 'I')
			{
				iGroup = 1;
				iCurIdx = 1;
				TargetChar = TargetChars[iCurIdx];
			}
			else if (str[i] == 'O')
			{
				iGroup = 0;
				iCurIdx = 0;
				TargetChar = TargetChars[iCurIdx];
			}
		}

		if (iGroup == 2 * iN + 1)
		{
			iCount++;
			iGroup-=2;

			iCurIdx = 1;
			TargetChar = TargetChars[iCurIdx];
		}
	}

	cout << iCount << "\n";

	return 0;
}

