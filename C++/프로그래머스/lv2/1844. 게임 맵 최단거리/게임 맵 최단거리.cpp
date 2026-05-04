#include<vector>
#include<queue>
using namespace std;

int iVisited[101][101] = {};
int solution(vector<vector<int> > maps)
{
	int answer = -1;

	//y
	int iN = maps.size() - 1;
	//x
	int iM = maps[0].size() - 1;

	queue<pair<pair<int, int>, int>> q = {};
	vector<pair<int, int>> vecDirs = {
		{1,0},
		{0,1},
		{-1,0},
		{0,-1}
	};
	q.push( {{0,0}, 1} );
	iVisited[0][0] = 1;

	while (!q.empty())
	{
		pair<pair<int, int>, int> Node = q.front();
		q.pop();

		if (Node.first.first == iN && Node.first.second == iM)
		{
			return Node.second;
		}


		for (auto& iter : vecDirs)
		{
			int iNextY = Node.first.first + iter.first;
			int iNextX = Node.first.second + iter.second;

			if (iNextX >= 0 && iNextX <= iM &&
				iNextY >= 0 && iNextY <= iN &&
				iVisited[iNextY][iNextX] == 0 &&
				maps[iNextY][iNextX] != 0)
			{
				iVisited[iNextY][iNextX] = 1;
				q.push({{ iNextY, iNextX }, Node.second + 1 });
			}
		}

	}

	return answer;
}
