#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    
	if (x == y)
		return 0;
    
	int answer = 0;

	int iDp[1000001] = {};
	iDp[x] = 0;
	if (x + n <= y)
		iDp[x + n] = 1;
	if(x*2 <= y)
		iDp[x * 2] = 1;
	if(x*3 <= y)
		iDp[x * 3] = 1;
	//-1로 초기화

	for (int i = x+1; i < y; ++i)
	{
		if ((i + n <= y) && iDp[i + n] != 0 && iDp[i] != 0)
			iDp[i + n] = min(iDp[i+n], iDp[i] + 1);
		else if((i + n <= y) && iDp[i + n] == 0 && iDp[i] != 0)
			iDp[i + n] = iDp[i] + 1;

		if ((i * 2 <= y) && iDp[i * 2] != 0 && iDp[i] != 0 )
			iDp[i * 2] = min(iDp[i*2], iDp[i] + 1);
		else if(i * 2 <= y && iDp[i * 2] == 0 && iDp[i] != 0)
			iDp[i * 2] = iDp[i] + 1;

		if (iDp[i] != 0 && (i * 3 <= y) && iDp[i * 3] != 0)
			iDp[i * 3] = min(iDp[i * 3], iDp[i] + 1);
		else if (i * 3 <= y && iDp[i * 3] == 0 && iDp[i] != 0)
			iDp[i * 3] = iDp[i] + 1;
	}

	if (iDp[y] == 0)
		return -1;

	return iDp[y];
}
