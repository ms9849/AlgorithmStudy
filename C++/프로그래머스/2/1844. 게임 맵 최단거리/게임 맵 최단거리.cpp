#include<vector>
#include <queue>
using namespace std;

/*
1. BFS로 풀어나가야 할듯 함. DFS로 하면 경우의 수가 너무 많아진다.
2. 도착하지 못하는 경우도 있다. 이 경우 예외처리에 조심할 것.
3. 맵의 크기는 직사각형일 수 있다. 
-> BFS 하기전에 미리 row col 사이즈 체크해둘 것.
*/

int iVisited[101][101] = {};

void BFS(const vector<vector<int>>& maps, int& answer)
{
    int iRowSize = maps.size() - 1;
    int iColSize = maps[0].size() - 1;
    
    vector<pair<int,int>> vecDirs = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
    
    //(x,y), depth 순.
    queue<pair<pair<int,int>,int>> q = {};
    //시작 위치.
    q.push(make_pair(make_pair(0,0), 1)); 
    
    while(!q.empty())
    {
        pair<int,int> CurPos = q.front().first;
        int iCurDepth = q.front().second;
        q.pop();
        
        if((CurPos.first == iRowSize) && (CurPos.second == iColSize) && (answer == -1 || iCurDepth < answer)) 
        {
            answer = iCurDepth;
        }
        
        for(int i=0; i<4; ++i)
        {
            pair<int,int> Dir = vecDirs[i];
            //그 방향이 방문한 적이 없다면, 그리고 범위 내에 있다면.
            if(CurPos.first + Dir.first >= 0 && CurPos.first + Dir.first <= iRowSize && CurPos.second + Dir.second >= 0 && CurPos.second + Dir.second <= iColSize && 0 == iVisited[CurPos.first + Dir.first][CurPos.second + Dir.second] && maps[CurPos.first + Dir.first][CurPos.second + Dir.second] != 0)
            {
                //방문 처리.
                iVisited[CurPos.first + Dir.first][CurPos.second + Dir.second] = 1;
                q.push(make_pair(make_pair(CurPos.first + Dir.first, CurPos.second + Dir.second), iCurDepth + 1));
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;
 
    BFS(maps, answer);
    
    return answer;
}