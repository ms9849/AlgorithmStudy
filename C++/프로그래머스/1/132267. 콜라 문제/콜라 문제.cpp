#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
	int answer = 0;
	
	while (n > 0)
	{
		if (n - a >= 0)
		{
			n -= a;
			n += b;
			answer += b;
		}
		else
			break;
	}

	return answer;
}