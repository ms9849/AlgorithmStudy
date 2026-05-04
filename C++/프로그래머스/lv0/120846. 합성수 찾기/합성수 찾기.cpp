#include <string>
#include <vector>

using namespace std;

int isCombine[101] = { };

int solution(int n) {
	int answer = 0;

	for (int i = 2; i <= n; ++i)
	{
		int iCount = 2;
		while (iCount * i <= 100)
		{
			isCombine[iCount * i] = 1;
			iCount++;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (1 == isCombine[i])
		{
			answer++;
		}
	}

	return answer; 
}