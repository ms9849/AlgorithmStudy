#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		int iSum = i;
		for (int j = i+1; j <= n; ++j)
		{
			if (iSum == n)
				answer++;
			else if (iSum > n)
				break;

			iSum += j;
		}
	}

	return answer + 1;
}