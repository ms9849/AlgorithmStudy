#include <string>
#include <vector>

using namespace std;

/*
자릿수의 합으로 나누어 떨어지는 수 -> 하샤드 수.
*/
bool solution(int x) {
    bool answer = true;
    
    int iOrigin = x;
    int iSum = 0;
    
    while(x != 0)
    {
        iSum += x%10;
        x/=10;
    }
    
    answer = (iOrigin % iSum == 0);
    
    return answer;
}