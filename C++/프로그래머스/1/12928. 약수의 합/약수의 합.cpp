#include <string>
#include <vector>

using namespace std;

int SumDivs(int n)
{
    int iAnswer = 0;
    for(int i=1; i<=n; ++i)
    {
        if(n%i == 0)
            iAnswer += i;
    }
    
    return iAnswer;
}

int solution(int n) {
    int answer = 0;
    
    answer = SumDivs(n);
    
    return answer;
}