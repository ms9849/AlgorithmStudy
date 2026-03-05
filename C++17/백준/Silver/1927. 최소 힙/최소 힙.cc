#include <iostream>
#include <queue>

using namespace std;

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq = {};
	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		switch (iNum)
		{
		case 0:
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << "0\n";

			break;
		default:
			pq.emplace(iNum);
			break;
		}
	}

	return 0;	
}