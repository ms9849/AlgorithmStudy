#include <string>
#include <vector>
#include <map>

using namespace std;

int iDp[1000]= {};

int solution(vector<int> elements) {
	map<int, int> mapNums = {};
	int iLength = elements.size();
	int iSum = {};

	iDp[0] = elements[0];
	iSum = elements[0];

	for (int i = 1; i < iLength; ++i)
	{
		iDp[i] = iDp[i - 1] + elements[i];
		iSum += elements[i];
	}

	mapNums[iSum] = 1;
	mapNums[iDp[0]] = 1;

	//인덱스 벗어난 녀석들의 부분 수열
	for (int i = 0; i < iLength; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int iDiff = iDp[i] - iDp[j];
			mapNums[iSum - iDiff] = 1;
		}
	}

	//인덱스 벗어나지 않은 녀석들의 부분 수열
	for (int i = 0; i < iLength; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int iDiff = iDp[i] - iDp[j];
			mapNums[iDiff] = 1;
		}
	}


	return mapNums.size();
}
