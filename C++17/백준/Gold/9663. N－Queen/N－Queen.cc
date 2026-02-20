#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iBoard[16][16] = {};
int iN;
int iCount = 0;

// N-Queen 문제.
// N x N 이니까, 한 줄당 반드시 하나의 퀸이 존재한다.
// 그럼 줄을 Depth로 삼아서 백트래킹을 해보는건? iBoard를 Visited 함수로 취급해서
// 계산 굴리면 될 것 같은데?

//퀸은 8방향으로 이동 가능하고..
pair<int, int> Directions[8] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 1},
	{-1,-1},
	{1, -1},
	{-1, 1}
};

// 보드 안정성 체크
bool Check_Bound(int iY, int iX)
{
	return (iX >= 1 && iX <= iN) && (iY >= 1 && iY <= iN);
}

// 퀸 8방향 경로 값 변경
void Set_QueenPath(int iY, int iX, int iValue)
{
	for (int i = 0; i < 8; ++i)
	{
		int iCurY = iY;
		int iCurX = iX;

		while (true == Check_Bound(iCurY, iCurX))
		{
			iBoard[iCurY][iCurX] += iValue;

			iCurY += Directions[i].second;
			iCurX += Directions[i].first;
		}
	}
}

void BackTracking(int iDepth)
{
	if (iDepth > iN)
	{
		iCount++;
		return;
	}
	// 8방향에 대해서 체크
	for (int i = 1; i <= iN; ++i)
	{
		if (0 == iBoard[iDepth][i])
		{
			Set_QueenPath(iDepth, i, 1);
			BackTracking(iDepth + 1);
			//그냥 지워버리는게 아니라 본인이 칠한 부분만..
			Set_QueenPath(iDepth, i, -1);
		}
	}
}

int main(void* pArg)
{
	cin >> iN;

	BackTracking(1);

	cout << iCount << "\n";

	return 0;
}