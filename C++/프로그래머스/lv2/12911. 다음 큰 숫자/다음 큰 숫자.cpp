#include <string>
#include <vector>
#include <stack>

using namespace std;

int CountOne(int n)
{
	int iResult = 0;
	stack<char> st = {};
	while (1)
	{
		st.push(n % 2 + '0');
		
		if (n <= 1)
			break;

		n /= 2;
	}

	while (!st.empty())
	{
		if (st.top() == '1')
			iResult++;

		st.pop();
	}

	return iResult;
}

int solution(int n) {
	int iCount = CountOne(n);
	int iStart = n+1;

	while (1)
	{
		int iOneCount = CountOne(iStart);

		if (iCount == iOneCount)
		{
			return iStart;
		}

		iStart++;
	}
}
