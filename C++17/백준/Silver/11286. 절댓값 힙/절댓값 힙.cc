#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iN;

	cin >> iN;

	auto cmp = [](const int& lhs, const int& rhs)->bool {
		if (abs(lhs) == abs(rhs))
			return lhs > rhs;
		else
			return abs(lhs) > abs(rhs);
		};

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < iN; ++i)
	{
		int iSour = {};

		cin >> iSour;

		switch (iSour)
		{
		case 0:
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{	
				cout << "0\n";
			}

			break;

		default:
			pq.push(iSour);

			break;
		}
	}

	return 0;
}