#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(n > m)
    {
        int iTemp = n;
        n = m;
        m = iTemp;
    }
    
    int iMin = 0;
    int iMax = 0;
    
    for(int i=1; i<=n; ++i)
    {
        if(n%i == 0 && m%i == 0)
            iMin = i;
    }
    
    iMax = n * m / iMin;
    
    answer.push_back(iMin);
    answer.push_back(iMax);
    
    return answer;
}