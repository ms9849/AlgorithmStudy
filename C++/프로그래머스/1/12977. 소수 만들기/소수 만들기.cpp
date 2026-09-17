#include <vector>
#include <iostream>
using namespace std;

bool IsMinor(int iNum)
{
    for(int i=2; i<iNum; ++i)
    {
        if(iNum%i == 0)
            return false;
    }
    return true;
}


int solution(vector<int> nums) {   
    int iSize = nums.size();
    int iAnswer = 0;
    
    for(int i=0; i<iSize; ++i)
    {
        for(int j=i+1; j<iSize; ++j)
        {
            for(int k=j+1; k<iSize; ++k)
            {
                int iNum = nums[i] + nums[j] + nums[k];
                
                if(IsMinor(iNum))
                    iAnswer++;
            }
        }
    }

    return iAnswer;
}