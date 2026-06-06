#include <string>
#include <vector>

using namespace std;
/*
가로가 무조건 기니까.. 가로부터 증가시키면 되겠네?
*/
int iWidthAnswer = {};
int iHeightAnswer = {};

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int iTotal = brown + yellow;
    
    for(int i=3; i<=iTotal; ++i)
    {
        for(int j=3; j<=i; ++j)
        {
            int iCurrentBrown = i*2 + j*2 - 4;
            int iCurrentYellow = (i-2) * (j-2);
            
            if(iCurrentBrown == brown && iCurrentYellow == yellow)
            {
                    answer.push_back(i);
                    answer.push_back(j);
                
                    return answer;
            }           
        }
    }
    
}