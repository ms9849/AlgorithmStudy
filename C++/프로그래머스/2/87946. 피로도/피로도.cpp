#include <string>
#include <vector>

using namespace std;

int iVisited[5001] = {};

void DFS(int& k, const vector<vector<int>>& dungeons, int iCurDepth, int& iMaxDepth)
{
    if(iMaxDepth < iCurDepth)
        iMaxDepth = iCurDepth;
    
    int iSize = dungeons.size();
    
    for(int i=0; i<iSize; ++i)
    {
        if(0 == iVisited[i] && k >= dungeons[i][0])
        {
            iVisited[i] = 1;
            k -= dungeons[i][1];
            
            DFS(k, dungeons, iCurDepth + 1, iMaxDepth);
            
            iVisited[i] = 0;
            k += dungeons[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    DFS(k,dungeons, 0, answer);
    
    
    return answer;
}