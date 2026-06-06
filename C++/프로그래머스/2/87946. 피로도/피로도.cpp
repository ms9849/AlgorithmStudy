#include <string>
#include <vector>

using namespace std;

//가거나, 가지 않거나..
//최대가 나오려면 계속 탐사를 하긴 해야겠지?..
//dp로도 풀이 가능해보이지만 완탐이 가장 직관적일 것.

int iVisited[10] = {};
int iMaxDungeons = {};
int iNumDungeons = {};
vector<vector<int>> vecDungeons = {};
/* 종료 조건 */
// 1. 모든 던전을 탐험함
// 2. 더 이상 피로도 조건에 맞는 던전이 없음.

void Recursion(int iCurPower, int iCurDungeons)
{
    bool isRaidable = { false };
    for(int i=0; i<iNumDungeons; ++i)
    {
        //최소 필요 피로도
        int iRequirePower = vecDungeons[i][0];
        //사용 피로도
        int iUsePower = vecDungeons[i][1]; 
        
        if(iVisited[i] == 0 &&
          iCurPower >= iRequirePower &&
          iCurPower >= iUsePower)
        {
            isRaidable = true;
            
            iVisited[i] = 1;
            Recursion(iCurPower - iUsePower, iCurDungeons + 1);
            iVisited[i] = 0;
        }
    }
    
    if(false == isRaidable)
    {
        iMaxDungeons = iMaxDungeons > iCurDungeons ? iMaxDungeons : iCurDungeons;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int iAnswer = { -1 };
    vecDungeons = dungeons;
    iNumDungeons = dungeons.size();
    
    Recursion(k, 0);
    
    return iMaxDungeons;
}