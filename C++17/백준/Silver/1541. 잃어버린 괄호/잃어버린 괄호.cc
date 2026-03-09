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
	string strVal;
	string strInt = {} ;

	int iResult = 0;
	int iTempSum = 0;

	bool isToggle = false;

	cin >> strVal;

	for (int i = strVal.size() - 1; i >=0; --i)
	{

		if (strVal[i] >= '0' && strVal[i] <= '9')
		{
			strInt += strVal[i];
		}
		else if (strVal[i] == '+' || strVal[i] == '-')
		{
			reverse(strInt.begin(), strInt.end());
			iTempSum += stoi(strInt);

			strInt = {};

			if (strVal[i] == '-')
			{
				iResult -= iTempSum;
				iTempSum = 0;
			}
		}
	}

	reverse(strInt.begin(), strInt.end());
	iTempSum += stoi(strInt);
	iResult += iTempSum;

	cout << iResult << "\n";

	return 0;
}