#include <string>
#include <vector>

using namespace std;

/*
2x + 2y = brown +4
(x - 1) * (y - 1) = yellow
xy - x -y + 1 = yellow

x + y = brown /2 + 2 

xy = yellow + (brown / 2 +2) - 1

y = brown / 2 + 2 - x;
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //brown은 8 이상.
    //yellow는 1 이상.
    //3x3이 제일 작은거겠지.
    
    int iX = 3;
    int iY = 3;
    
    while(((iX-2)*(iY-2) != yellow || (2*iX + 2*iY != brown + 4)))
    {
        if(iX >= iY+1)
            iY++;
        else
        {
            iX++;
            iY = 3;
        }
    }
    
    answer.push_back(iX);
    answer.push_back(iY);
    
    return answer;
}