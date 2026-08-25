#include <string>
#include <vector>
#include "math.h"

using namespace std;

/*
최대값이 엄청나게 크기 때문에, left가 X행 Y열이라면, max(x,y)의 값으로 시작해서 카운트 해야함.

행 구하는 법 -> left / n + left % n 으로, 0행(실제론 1행), 2열임을 알 수 잇음 


1, 2, 3
2, 2, 3
3, 3, 3

3,2,2,3 으로 배열을 채울 수 있음.
*/

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left; i<=right; ++i)
    {
        answer.push_back(max(i / n , i % n) + 1);
    }
    
    return answer;
}