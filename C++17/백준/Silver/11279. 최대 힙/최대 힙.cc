#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iN;
	cin >> iN;
	
	for (int i = 0; i < iN; ++i)
	{
		int iSour;
		cin >> iSour;

		if (iSour == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(iSour);
		}
	}

	return 0;
}