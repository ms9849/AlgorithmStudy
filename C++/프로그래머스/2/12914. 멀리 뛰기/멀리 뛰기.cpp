#include <string>
#include <vector>

using namespace std;

/*
dp.. 같은데? 2칸 또는 1칸 뛸 수 있으니까,
3칸째부터 측정 시작하면 된다.
*/

long long iDp[2001] = {};

long long solution(int n) {
    long long answer = 0;
    
    iDp[1] = 1;
    iDp[2] = 2;
    
    for(int i=3; i<=n; ++i)
    {
        iDp[i] = (iDp[i-1] + iDp[i-2]) % 1234567;
    }
    
    return iDp[n];
}