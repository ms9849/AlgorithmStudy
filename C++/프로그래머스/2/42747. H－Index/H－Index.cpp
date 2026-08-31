#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int iMid = 0;
    int iMin = 0;
    int iMax = citations.size()-1;
    int iSize = citations.size();
    
    sort(citations.begin(), citations.end());
    
    while(iMin <= iMax)
    {
        iMid = (iMin + iMax) / 2;
        // ival번 이상 인용된 논문이,
        int iVal = citations[iMid];
        // iSize - iMid 개 존재함.
        int iCount = iSize - iMid;
        // 3개 이상의 논문이 1회 이상 인용되었다면..
        // 논문 3(h)개는 안되지.
        if(iCount <= iVal)
        {
            iMax = iMid -1;
            answer = iCount;
        }
        else
        {
            iMin = iMid+1;
        }
        
    }
    
    
    
    return answer;
}