#include <iostream>
using namespace std;

int main(void* pArg)
{
	int iN;

	cin >> iN;

	int	dpMax[3][2] = {};
	int dpMin[3][2] = {};
	for (int i = 1; i <= iN; ++i)
	{
		int iFirst, iSecond, iThird;
		cin >> iFirst >> iSecond >> iThird;

		if (i == 1)
		{
			dpMax[0][1] = dpMax[0][0] = iFirst;
			dpMax[1][1] = dpMax[1][0] = iSecond;
			dpMax[2][1] = dpMax[2][0] = iThird;

			dpMin[0][1] = dpMin[0][0] = iFirst;
			dpMin[1][1] = dpMin[1][0] = iSecond;
			dpMin[2][1] = dpMin[2][0] = iThird;
		}

		else
		{
			dpMax[0][1] = max(dpMax[0][0], dpMax[1][0]) + iFirst;
			dpMax[1][1] = max(max(dpMax[0][0], dpMax[1][0]), dpMax[2][0]) + iSecond;
			dpMax[2][1] = max(dpMax[2][0], dpMax[1][0]) + iThird;

			dpMax[0][0] = dpMax[0][1]; 
			dpMax[1][0] = dpMax[1][1];
			dpMax[2][0] = dpMax[2][1];

			//min
			dpMin[0][1] = min(dpMin[0][0], dpMin[1][0]) + iFirst;
			dpMin[1][1] = min(min(dpMin[0][0], dpMin[1][0]), dpMin[2][0]) + iSecond;
			dpMin[2][1] = min(dpMin[2][0], dpMin[1][0]) + iThird;

			dpMin[0][0] = dpMin[0][1];
			dpMin[1][0] = dpMin[1][1];
			dpMin[2][0] = dpMin[2][1];
		}
	}

	cout << max(max(dpMax[0][1], dpMax[1][1]), dpMax[2][1]) << " ";
	cout << min(min(dpMin[0][1], dpMin[1][1]), dpMin[2][1]);

	return 0;
}