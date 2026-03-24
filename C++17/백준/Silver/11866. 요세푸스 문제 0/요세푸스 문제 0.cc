#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void* pArg)
{
	queue<int> q = {};

	queue<int> result = {};

	int iN, iK;
	cin >> iN >> iK;

	for (int i = 1; i <= iN; ++i)
	{
		q.push(i);
	}

	
	while (!q.empty())
	{
		for (int i = 0; i < iK-1; ++i)
		{
			int iFront = q.front();
			q.pop();
			q.push(iFront);
		}

		int iTarget = q.front();
		q.pop();
		result.push(iTarget);
	}
	
	cout << "<";
	
	while (!result.empty())
	{
		if (result.size() > 1)
			cout << result.front() << ", ";
		else
			cout << result.front();
		result.pop();
	}

	cout << ">";

	return 0;
}