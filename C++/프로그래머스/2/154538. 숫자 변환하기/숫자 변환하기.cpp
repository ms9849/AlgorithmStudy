#include <string>
#include <vector>

using namespace std;

/*
몇번의 연산을 통해 x에서 목표 y로 변환이 가능한지 확인하는 문제.
아마 DP일 것. +, *2, *3 첫 인덱스만 계산해놓고 해도?..
*/

int iDp[1000001] = {};

int solution(int x, int y, int n) {
    int answer = 0;

    if(x+n <= y)
        iDp[x+n] = 1;
    if(x*2 <= y)
        iDp[x*2] = 1;    
    if(x*3 <= y)
        iDp[x*3] = 1;
    
    for(int i=x; i<=y; ++i)
    {
        if(iDp[i] != 0)
        {
            if(i+n <= y)
            {
                //무언가 이미 도달할 수 있는 방법이 있다면?
                if(iDp[i+n] != 0)
                    iDp[i+n] = min(iDp[i+n], iDp[i] + 1);
                else
                    iDp[i+n] = iDp[i] + 1;   
            }
            if(i*2 <= y)
            {
                if(iDp[i*2] != 0)
                    iDp[i*2] = min(iDp[i*2], iDp[i] + 1);
                else
                    iDp[i*2] = iDp[i] + 1;
            }

            if(i*3 <= y)
            {
                if(iDp[i*3] != 0)       
                    iDp[i*3] = min(iDp[i*3], iDp[i] + 1);
                else
                    iDp[i*3] = iDp[i] + 1;   
            }   
        }
    }

    if(x == y)
        return 0;
    if(iDp[y] == 0)
        return -1;
    
    return iDp[y];
}