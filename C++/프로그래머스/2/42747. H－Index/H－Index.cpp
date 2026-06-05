#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int iAnswer = 0;
    sort(citations.begin(), citations.end());
    
    int iMax = citations[citations.size()-1];
    
    for(int i=0; i<iMax; ++i)
    {
        int iHCount = 0;
        for(int j=0; j<citations.size(); ++j)
        {
            if(citations[j] >= i)
                iHCount++;
        }
        
        if(iHCount >= i)
            iAnswer = i;
        else
            break;
    }
    
    
    return iAnswer;
}