#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
같은 크기의 수를 곱한다면, 한쪽이 작아야 곱의 결과가 최대한 작아짐.
-> 어떤 수식이 있다기보단.. 직관적 감각이긴 한데, 일단 이대로 가보자.
*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](int lhs, int rhs)->bool {
       return lhs > rhs;
    });
    
    int iNum = A.size();
    for(int i=0; i<iNum; ++i)
    {
        answer += A[i] * B[i];
    }
    
    return answer;
}