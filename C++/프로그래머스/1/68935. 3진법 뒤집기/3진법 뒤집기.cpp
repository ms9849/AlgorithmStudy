#include <string>
#include <vector>
#include "math.h"

using namespace std;

long long Change(int iNum, int iType)
{
	string strResult = {};

	while (iNum != 0)
	{
		strResult += ('0' + (iNum % iType));
		iNum /= iType;
	}

	return stol(strResult);
}


int solution(int n) {

	long long iReverseThree = Change(n, 3);
	int iResult = 0;
	int iCount = 0;

	while (iReverseThree != 0)
	{
		iResult += (iReverseThree % 10) * pow(3, iCount);
		iReverseThree /= 10;

		iCount++;
	}

	return iResult;
}
