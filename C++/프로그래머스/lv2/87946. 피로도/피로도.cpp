#include <string>
#include <vector>

using namespace std;

int iVisited[9] = {};
int iDungeonCnt = {};
int iIdx = {};
int iResult = {};
vector<vector<int>> DungeonInfos = {};

void Recursion(int iCurK, int iCurrentCount)
{
	if (iCurrentCount == iDungeonCnt)
	{
		int iTemp = 0;
		for (int i = 0; i < iDungeonCnt; ++i)
		{
			if (iVisited[i] == 1)
			{
				iTemp++;
			}
		}

		if (iTemp > iResult)
			iResult = iTemp;

		return;
	}

	for (int i = 0; i < iDungeonCnt; ++i)
	{
		if (iVisited[i] == 0)
		{
			if (iCurK >= DungeonInfos[i][0])
			{
				iVisited[i] = 1;
				iCurK -= DungeonInfos[i][1];

				Recursion(iCurK, iCurrentCount + 1);

				iVisited[i] = 0;
				iCurK += DungeonInfos[i][1];
			}
			else
			{
				iVisited[i] = 2;
				Recursion(iCurK, iCurrentCount + 1);
				iVisited[i] = 0;
			}
		}
	}
}
int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	DungeonInfos = dungeons;
	iDungeonCnt = dungeons.size();

	Recursion(k, 0);

	answer = iResult;

	return answer;
}
