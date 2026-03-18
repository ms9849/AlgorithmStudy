#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iCount = {};
int iSize = {};
int iBoard[17][17] = {};
enum class DIR { Vert, Hori, Diag };

//가로일땐 그대로 전진하거나, 대각선 회전
//세로일땐 그대로 전진하거나, 대각선 회전
//대각선일땐 모든 방향으로 회전하며 전진 가능.

void Recursion(pair<int, int> iHead, pair<int, int> iTail, DIR eDir)
{
	if (iTail.first == iSize && iTail.second == iSize)
	{
		iCount++;
		return;
	}

	switch (eDir)
	{
	case DIR::Hori:
		// 가로일때 가로로 쭉 이어서 가.
		if (iTail.second + 1 <= iSize 
			&& iBoard[iTail.first][iTail.second + 1] != 1)
		{
			Recursion(iTail, make_pair(iTail.first, iTail.second + 1), DIR::Hori);
		}

		// 가로일때 꺾어서 가.
		if (iTail.first + 1 <= iSize 
			&& iTail.second + 1 <= iSize 
			&& iBoard[iTail.first + 1][iTail.second + 1] != 1
			&& iBoard[iTail.first][iTail.second + 1] != 1
			&& iBoard[iTail.first + 1][iTail.second] != 1)
		{
			Recursion(iTail, make_pair(iTail.first + 1, iTail.second + 1), DIR::Diag);
		}

		break;

	case DIR::Vert:
		// 세로일때 쭉 세로로 가.
		if (iTail.first + 1 <= iSize
			&& iBoard[iTail.first + 1][iTail.second] != 1)
		{
			Recursion(iTail, make_pair(iTail.first + 1, iTail.second), DIR::Vert);
		}

		// 세로일때 꺾어서 가.
		if (iTail.first + 1 <= iSize
			&& iTail.second + 1 <= iSize
			&& iBoard[iTail.first + 1][iTail.second + 1] != 1
			&& iBoard[iTail.first][iTail.second + 1] != 1
			&& iBoard[iTail.first + 1][iTail.second] != 1)
		{
			Recursion(iTail, make_pair(iTail.first + 1, iTail.second + 1), DIR::Diag);
		}

		break;

	case DIR::Diag:
		//대각선일때 가로로 가.
		if (iTail.second + 1 <= iSize
			&& iBoard[iTail.first][iTail.second + 1] != 1)
		{
			Recursion(iTail, make_pair(iTail.first, iTail.second + 1), DIR::Hori);
		}
		//대각선일떄 세로로 가.
		if (iTail.first + 1 <= iSize
			&& iBoard[iTail.first + 1][iTail.second] != 1)
		{
			Recursion(iTail, make_pair(iTail.first + 1, iTail.second), DIR::Vert);
		}
		//대각선일때 꺾어서 가.
		if (iTail.first + 1 <= iSize
			&& iTail.second + 1 <= iSize
			&& iBoard[iTail.first + 1][iTail.second + 1] != 1
			&& iBoard[iTail.first][iTail.second + 1] != 1
			&& iBoard[iTail.first + 1][iTail.second] != 1)
		{
			Recursion(iTail, make_pair(iTail.first + 1, iTail.second + 1), DIR::Diag);
		}
		break;

	default:
		break;

	}
}

int main(void* pArg)
{
	cin >> iSize;

	for (int i = 1; i <= iSize; ++i)
	{
		for (int j = 1; j <= iSize; ++j)
		{
			cin >> iBoard[i][j];
		}
	}

	Recursion(make_pair(1, 1), make_pair(1, 2), DIR::Hori);

	cout << iCount << "\n";

	return 0;
}