#include <string>
#include <vector>

/*
최소 3x3 이상의 길이를 가진 카펫.
2x + 2y - 4 = brown
xy - 2x - 2y + 4 = yellow

xy = brown + yellow

*/
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int iX=3;
    int iY=3;
    
    while(brown + yellow != iX * iY || 2*iX + 2*iY - 4 != brown)
    {
        if(iY == iX)
        {
            iX++;
            iY=3;
        }
        else
        {
            iY++;   
        }
    }
    
    answer.push_back(iX);
    answer.push_back(iY);
    
    return answer;
}