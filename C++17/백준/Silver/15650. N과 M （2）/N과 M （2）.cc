#include <iostream>

using namespace std;

int iVisited[9] = {};

void DFS(int iStart, int iCount, int iMax, int iMaxNum)
{
	if (iCount >= iMax)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (iVisited[i] == true)
				cout << i << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = iStart; i <= iMaxNum; ++i)
	{
		if (iVisited[i] == false)
		{
			iVisited[i] = true;
			DFS(i, iCount + 1, iMax, iMaxNum);
			iVisited[i] = false;
		}
	}
}

int main(void* pArg)
{
	int iN{}, iM{};

	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
	{
		iVisited[i] = true;
		DFS(i, 1, iM, iN);
		iVisited[i] = false;
	}

	return 0;
}