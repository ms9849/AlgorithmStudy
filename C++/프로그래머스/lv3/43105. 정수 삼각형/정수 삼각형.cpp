#include <string>
#include <vector>

using namespace std;

int iDp[500][500] = {};

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	iDp[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j - 1 >= 0)
				iDp[i][j] = max(iDp[i - 1][j], iDp[i - 1][j - 1]) + triangle[i][j];
			else
				iDp[i][j] = iDp[i - 1][j] + triangle[i][j];
		}
	}

	int iMax = 0;
	for (int i = 0; i < triangle.size(); ++i)
	{
		iMax = max(iMax, iDp[triangle.size() - 1][i]);
	}

	return iMax;
}