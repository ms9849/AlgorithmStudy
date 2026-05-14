#include <string>
#include <vector>

using namespace std;


int iArray[1024][1024] = {};
int iSize = {};
int iAnswer[2] = {};

void QuadTree(int iStartY, int iStartX, int iSize)
{
	if (iSize == 1)
	{
		iAnswer[iArray[iStartY][iStartX]]++;
		return;
	}

	bool isAllSame = { true };
	int iFlag = iArray[iStartY][iStartX];

	for (int i = iStartY; i < iStartY + iSize; ++i)
	{
		for (int j = iStartX; j < iStartX + iSize; ++j)
		{
			//다시 압축해야 함.
			if (iArray[i][j] != iFlag)
			{
				isAllSame = false;
				break;
			}
		}
	}

	//만약 모두 같다면,
	if (true == isAllSame)
	{
		iAnswer[iFlag]++;
		return;
	}
	else
	{
		QuadTree(iStartY, iStartX, iSize / 2);
		QuadTree(iStartY + iSize / 2, iStartX, iSize / 2);
		QuadTree(iStartY, iStartX + iSize / 2, iSize / 2);
		QuadTree(iStartY + iSize / 2, iStartX + iSize / 2, iSize / 2);
	}
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer = {};

	iSize = arr.size();

	for (int i=0; i< iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			iArray[i][j] = arr[i][j];

	QuadTree(0, 0, iSize);

	answer = { iAnswer[0], iAnswer[1] };
	return answer;
}
