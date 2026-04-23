#include <string>
#include <vector>

using namespace std;
vector<int> solution(int brown, int yellow) {
	vector<int> answer = {};

	//세로는 최소 3.
	//가로도 최소 3에서 시작.

	int iHeight = 3;
	int iWidth = 3;

	for (int iHeight = 3; iHeight <= 5000; ++iHeight)
	{
		for (int iWidth = iHeight; iWidth <= 5000; ++iWidth)
		{
			int iCalcBrown  = (iHeight * 2 + iWidth * 2) - 4;
			int iCalcYellow = (iHeight - 2) * (iWidth - 2); 

			if (iCalcBrown == brown && iCalcYellow == yellow)
			{
				answer.push_back(iWidth);
				answer.push_back(iHeight);

				return answer;
			}
		}
	}

	return answer;
}

