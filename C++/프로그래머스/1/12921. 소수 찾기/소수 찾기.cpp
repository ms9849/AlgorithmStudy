#include <string>
#include <vector>

using namespace std;

int iDp[1000001] = {};

int solution(int n) 
{
    int answer = 0;
    
    for(int i=2; i<1000; ++i)
    {
        for(int j=2; i*j <= 1000000; ++j)
        {
            iDp[i*j] = 1; 
        }
    }
    
    for(int i=2; i<=n; ++i)
    {
        if(iDp[i] == 0)
            answer++;
    }
    
    return answer;
}