#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>
#include <set>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());

	sort(B.begin(), B.end(), [](int lhs, int rhs)->bool {
		return lhs > rhs;
	});

	for (int i = 0; i < A.size(); ++i)
	{
		answer += A[i] * B[i];
	}

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution({1,2,3,4,5,6,7,8}, {1,2,3,4,5,6,7,8});
	return 0;
}