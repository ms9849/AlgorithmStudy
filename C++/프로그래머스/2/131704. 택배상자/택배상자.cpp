#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
스택을 이용한 시뮬레이션 문제.
*/
/* 스택을 이용한 시뮬레이션 문제. */
int solution(vector<int> order) {

	int iCurIdx = 0;
	int iAnswer = 0;
	stack<int> st = {};

	//메인 운송 장치 처리.
	for (int i = 0; i < order.size(); ++i)
	{

		while (!st.empty() && st.top() == order[iCurIdx])
		{
			st.pop();
			iCurIdx++;
		}

		if (order[iCurIdx] == (i + 1))
			iCurIdx++;
		else if (order[iCurIdx] != (i+1))
		{
			st.push(i + 1);
		}
	}

	while (!st.empty() && st.top() == order[iCurIdx])
	{
		st.pop();
		iCurIdx++;
	}


	return iCurIdx;
}

