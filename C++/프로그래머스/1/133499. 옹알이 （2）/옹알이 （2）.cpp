#include <string>
#include <vector>

using namespace std;

/*
아마 브루트 포스, 혹은 DFS에 가까운 완탐일 것.
*/


int solution(vector<string> babbling) {
    int answer = 0;
    int iSize = babbling.size();
    
    for(int i=0; i<iSize; ++i)
    {
        string strBabbling = babbling[i];
        int iLength = babbling[i].size();
        bool isBabble = false;
        int PreBabble = -1;
        //여기서 각 케이스에 대해 검사..를 해야됨.
        for(int j=0; j<iLength; ++j)
        {
            //인덱스 벗어나지 않는지도 체크.
            if(j+2 < iLength &&
               strBabbling[j] == 'a' &&
              strBabbling[j+1] == 'y' &&
              strBabbling[j+2] == 'a' &&
                PreBabble != 0)
            {
                j += 2;
                isBabble = true;
                PreBabble = 0;
            }
            else if(j+1 < iLength &&
              strBabbling[j] == 'y' &&
              strBabbling[j+1] == 'e' &&
                PreBabble != 1)
            {
                j += 1;
                isBabble = true;
                PreBabble = 1;
            }
            else if(j+1 < iLength &&
              strBabbling[j] == 'm' &&
              strBabbling[j+1] == 'a' &&
                PreBabble != 2)
            {
                j += 1; 
                isBabble = true;
                PreBabble = 2;
            }
            else if(j+2 < iLength &&
               strBabbling[j] == 'w' &&
              strBabbling[j+1] == 'o' &&
              strBabbling[j+2] == 'o' &&
                PreBabble != 3)
            {
                j += 2;
                isBabble = true;
                PreBabble = 3;
            }
            else
            {
                isBabble = false;
                break;
            }
        }
        //옹알이라면.
        if(true == isBabble)
            answer++;
    }
    
    return answer;
}