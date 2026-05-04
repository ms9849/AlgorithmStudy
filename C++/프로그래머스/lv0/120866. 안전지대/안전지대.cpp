#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
	int answer = 0;

	vector<pair<int, int>> vecDirs = {
		{1,0},
		{1,1},
		{1,-1},
		{0,1},
		{0,-1},
		{-1,0},
		{-1,1},
		{-1,-1}
	};

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[i][j] == 1)
			{
				for (auto& iter : vecDirs)
				{
					int iNextY = i + iter.first;
					int iNextX = j + iter.second;

					if (iNextX >= 0 && iNextX < board.size() &&
						iNextY >= 0 && iNextY < board.size() &&
						board[iNextY][iNextX] == 0)
						board[iNextY][iNextX] = 2;
				}
			}
		}
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[i][j] == 0)
			{
				answer++;
			}
		}
	}

	return answer;
}
