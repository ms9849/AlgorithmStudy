#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	//n개의 논문 존재.
	int iAllCount = citations.size();
	
	//일단 정렬하고..
	sort(citations.begin(), citations.end());

	//주어진 숫자가 없으니까 이분탐색으로 반복해서 찾아야 한다.
	// h의 범위는 0 ~ n 사이.
	
	int iMax = 0;


	for(int i=0; i< iAllCount; ++i)
	{
	
		//h편 이상이 h번 이상 인용됐다면.
		if (citations[i] >= iAllCount - i)
		{
			if(iMax < iAllCount - i)
				iMax = iAllCount - i;

		}
	}


	return iMax;
}