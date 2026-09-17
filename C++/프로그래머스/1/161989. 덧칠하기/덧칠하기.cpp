#include <string>
#include <vector>

using namespace std;

/*
걍 for문 돌면서, 다음인덱스 다다음 인덱스 쭉 한번에 칠할 수 있는지 체크하면 될 것 같은데?
*/

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int iSize = section.size();
    
    int iCount = 0;
    
    for(int i=0; i<iSize; ++i)
    {
        int iStart = i;
        //예제 1로 치면 2가 나오겠지.
        int iStartValue = section[i];

       for(int j=iStart+1; j<iSize; ++j)
        {
            if(section[j] - iStartValue + 1 <= m)
                i++;
        }
        
        iCount++;
    }
    
    return iCount;
}