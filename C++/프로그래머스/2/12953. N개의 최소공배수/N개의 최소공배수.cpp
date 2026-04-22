#include <string>
#include <vector>

using namespace std;

/*
에라토스테네스의 체를 써보자
*/
int iArray[101] = {};

int solution(vector<int> arr) {

	int iCount = 1;

	while (1)
	{
		bool isMin = { true };

		for (auto& iter : arr)
		{
			if (iCount % iter != 0)
			{
				isMin = false;
				continue;
			}
		}

		if (true == isMin)
			return iCount;

		iCount++;
	}
}