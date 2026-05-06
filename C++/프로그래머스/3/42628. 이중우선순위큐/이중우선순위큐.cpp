#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;


vector<int> solution(vector<string> operations) {

	vector<int> answer;

	map<int, int> mapCounter = {};
	priority_queue<int, vector<int>, less<int>> pqMax = {};
	priority_queue<int, vector<int>, greater<int>> pqMin = {};

	for (auto& iter : operations)
	{
		char cCmd = iter[0];
		int  iNum = stoi(iter.substr(iter.find(' ') + 1));

		switch (cCmd)
		{
		case 'D':
			if (iNum == -1)
			{
				if (!pqMin.empty() && mapCounter[pqMin.top()] > 0)
				{
					mapCounter[pqMin.top()]--;
					pqMin.pop();
				}

				while (!pqMin.empty() && mapCounter[pqMin.top()] == 0)
					pqMin.pop();
				while (!pqMax.empty() && mapCounter[pqMax.top()] == 0)
					pqMax.pop();
			}
			else if (iNum == 1)
			{
				if (!pqMax.empty() && mapCounter[pqMax.top()] > 0)
				{
					mapCounter[pqMax.top()]--;
					pqMax.pop();
				}

				while (!pqMin.empty() && mapCounter[pqMin.top()] == 0)
					pqMin.pop();
				while (!pqMax.empty() && mapCounter[pqMax.top()] == 0)
					pqMax.pop();
			}

			break;

		case 'I':
			pqMax.push(iNum);
			pqMin.push(iNum);
			
			mapCounter[iNum]++;
			break;
		}
	}

	if (pqMin.empty() || pqMax.empty())
		return { 0,0 };

	else
	{
		while (mapCounter[pqMax.top()] == 0)
			pqMax.pop();

		answer.push_back(pqMax.top());

		while (mapCounter[pqMin.top()] == 0)
			pqMin.pop();
		answer.push_back(pqMin.top());
	}

	return answer;
}

