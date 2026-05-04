#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {

	int iCameraPos = {-30001};
	int iAnswer = 0;

	sort(routes.begin(), routes.end(), [](vector<int> lhs, vector<int> rhs)->bool {
		return lhs[0] < rhs[0];
	});

	for (auto& iter : routes)
	{
		if (iCameraPos == -30001)
		{
			iCameraPos = iter[1];
			iAnswer++;
		}

		if (iCameraPos > iter[1])
		{
			iCameraPos = iter[1];
		}
		else if (iCameraPos < iter[0])
		{
			iCameraPos = iter[1];
			iAnswer++;
		}
	}

	return iAnswer;
}
