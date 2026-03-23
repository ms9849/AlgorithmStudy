#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int iArray[101][101] = {};

int iVisited[101][101] = {};

int main(void* pArg)
{
	int iN;

	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> iArray[i][j];
		}
	}

	for (int k = 0; k < iN; ++k)
	{
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				if (iArray[i][k] == 1 && iArray[k][j] == 1)
				{
					iArray[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cout << iArray[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}