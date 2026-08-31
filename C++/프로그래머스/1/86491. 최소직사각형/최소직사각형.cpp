#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int iTemp = {};
    int iSize = sizes.size();
    
    for(int i=0; i<iSize; ++i)
    {
        //오른쪽이 왼쪽보다 크다면, 
        if(sizes[i][0] < sizes[i][1])
        {
            //swap
            iTemp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = iTemp;
        }
    }
    
    int iLeftMax = -1;
    int iRightMax = -1;
    
    for(int i=0; i<iSize; ++i)
    {
        if(sizes[i][0] > iLeftMax)
            iLeftMax = sizes[i][0];
        
        if(sizes[i][1] > iRightMax)
            iRightMax = sizes[i][1];
    }
    
    answer = iLeftMax * iRightMax;
    
    
    return answer;
}