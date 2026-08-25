#include <iostream>
#include <vector>
using namespace std;

/*
무조건 DP로 풀어야함. 
완탐은 불가능.

항상 최대값을 얻어와야하는 그리드는 아님. -> 이전 조건이 발목을 잡기 때문.
dp로 매 순간 기록해서 그 순간의 최적값들을 전부 모아야한다.
*/

int iDp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i=0; i<4; ++i)
        iDp[0][i] = land[0][i];
    
    for(int i=1; i<land.size(); ++i)
    {
        for(int j=0; j<4; ++j)
        {
            int iMax = -1;
            
            for(int k=0; k<4; ++k)
            {
                 if(k != j)
                      iMax = max(iMax, iDp[i-1][k]);      
            }
            
            iDp[i][j] = iMax + land[i][j];
        }
    }
    
    for(int i=0; i<4; ++i)
    {
        answer = max(answer, iDp[land.size()-1][i]);
    }
    
    return answer;
}