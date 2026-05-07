#include <string>
#include <vector>
#include <map>
#include "math.h"
using namespace std;

#define MAX_NUM 9999999
// true라면 소수가 아님,
// false라면 소수
bool iArray[10000000] = {};
vector<int> iArrayNums = {};
map<int, int > Minority = {};
int iVisited[10] = {};
//에라토스테네스의 체로 미리 배열을 만들어두기?..

void Recursion(string CurNum, int iDepth)
{
	if (CurNum != "" && stoi(CurNum) != 0 && iArray[stoi(CurNum)] == false)
		Minority.emplace(stoi(CurNum), 1);

	if (iDepth == iArrayNums.size())
		return;

	for (int i = 0; i < iArrayNums.size(); ++i)
	{
		if (false == iVisited[i])
		{
			iVisited[i] = 1;
			Recursion(CurNum + (char)(iArrayNums[i] + '0'), iDepth + 1);
			iVisited[i] = 0;
		}
	}
}

int solution(string numbers) {
	int iSqrtMax = sqrt(MAX_NUM);
	int iStart = 2;
	iArray[1] = true;

	while (iStart <= iSqrtMax)
	{
		int iCount = 2;

		if (iStart != true)
		{
			while (iStart * iCount <= MAX_NUM)
			{
				iArray[iStart * iCount] = true;
				iCount++;
			}
		}
		
		iStart++;
	}


	for (int i = 0; i < numbers.length(); ++i)
	{
		iArrayNums.push_back(numbers[i] - '0');
	}

	Recursion("", 0);

	return Minority.size();
}
