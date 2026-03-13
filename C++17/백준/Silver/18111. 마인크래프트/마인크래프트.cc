#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
그냥 round 함수로 최적의 높이 찾은다음에..

거기에 도달할 수 있는지 체크하고..
안되면 깎고..
되면 쌓아 올려서 가야지
*/

int iMap[501][501] = {};

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int iMinHeight = -1;
	int iMinTime = 987654321;

	int iN, iM, iB;

	cin >> iN >> iM >> iB;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> iMap[i][j];
		}
	}
	

	for (int i = 0; i <= 256; ++i)
	{
		int iCurBlock = iB;
		int iCurTime = 0;

		for (int j = 0; j < iN; ++j)
		{
			for (int k = 0; k < iM; ++k)
			{
				if (iMap[j][k] < i)
				{
					iCurBlock -= (i - iMap[j][k]);
					iCurTime += (i - iMap[j][k]);
				}
				else if (iMap[j][k] > i)
				{
					iCurBlock += (iMap[j][k] - i);
					iCurTime += 2 * (iMap[j][k] - i);
				}
			}
		}

		if (iCurBlock < 0)
			continue;
		else // 최소값 비교해줘잉
		{
			if (iCurTime <= iMinTime)
			{
				iMinTime = iCurTime;
				iMinHeight = i;
			}
		}
	}

	cout << iMinTime << " " << iMinHeight << "\n";

	return 0;
}