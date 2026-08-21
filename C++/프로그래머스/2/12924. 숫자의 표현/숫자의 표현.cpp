#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i<=n; ++i)
    {
        int iSum = 0;
        int iStart = i;
        
        while(iSum < n)
        {
            iSum += iStart;
            iStart++;
            
            if(iSum == n)
                answer++;
        }
    }
    
    return answer;
}