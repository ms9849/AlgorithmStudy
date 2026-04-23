#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer = {};

	int iLeftRow = left / n;
	int iLeftCol = left % n;


	int iRightRow = right / n;
	int iRightCol = right % n;


	for (int i = iLeftRow; i <= iRightRow; ++i)
	{
		int j = i == iLeftRow ? iLeftCol : 0;

		while (j < n)
		{
			int iMax = i > j ? i + 1 : j + 1;

			answer.push_back(iMax);

			if (i == iRightRow && j == iRightCol)
				break;
			j++;
		}
	}

	return answer;
}
