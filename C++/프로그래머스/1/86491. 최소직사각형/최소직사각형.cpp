#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    for(auto& iter : sizes)
    {
        //Swap 알고리즘.
        //더 긴 길이가 0번째 인덱스에 오도록 처리한다.
        if(iter[1] > iter [0])
        {
            int iTemp = iter[0];
            iter[0] = iter[1];
            iter[1] = iTemp;
        }
    }
    
    int iWidthMax = {};
    int iHeightMax = {};
    
    for(auto& iter : sizes)
    {
        if(iter[0] > iWidthMax)
            iWidthMax = iter[0];
        if(iter[1] > iHeightMax)
            iHeightMax = iter[1];
    }
    
    return iWidthMax * iHeightMax;
}