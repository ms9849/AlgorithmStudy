#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int iNumber, vector<int> vecTimes) {
    long long iAnswer = 0;
    long long iLow = {};
    long long iMid = {};
    long long iHigh = {};
    
    sort(vecTimes.begin(), vecTimes.end());
    
    iLow = vecTimes[0] * (iNumber / vecTimes.size());
    iHigh = vecTimes[vecTimes.size()-1] * iNumber;
    
    while(iLow <= iHigh)
    {
        // overflow 방지.
        iMid = (iLow + iHigh)/2;
        
        long long iCanHandle = {};
        
        for(auto& iter : vecTimes)
        {
            iCanHandle += iMid / iter;
        }
        
        if(iCanHandle >= iNumber)
        {
            iHigh = iMid-1;
        }
        else if(iCanHandle < iNumber)
        {
            iLow = iMid+1;
        }
    }
    
    
    return iLow;
}