#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	for (auto& iter : sizes)
	{
		if (iter[0] < iter[1])
		{
			int iTemp = iter[1];
			iter[1] = iter[0];
			iter[0] = iTemp;
		}
	}

	int iMaxWidth = 0;
	int iMaxHeight = 0;

	for (int i = 0; i < sizes.size(); ++i)
	{
		if (sizes[i][0] > iMaxWidth)
			iMaxWidth = sizes[i][0];

		if (sizes[i][1] > iMaxHeight)
			iMaxHeight = sizes[i][1];
	}

	return iMaxHeight * iMaxWidth;
}

