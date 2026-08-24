#include <string>
#include <vector>

using namespace std;

/* 방문 배열은 미리 만들어놓자. */
int iVisited[201] = {};

void DFS(int iCurNode, const vector<vector<int>>& computers, int iNumComputers)
{
    //방문.
    iVisited[iCurNode] = 1;
    
    for(int i=0; i<iNumComputers; ++i)
    {
        //1. 자기자신이 아닌 노드에 방문이 가능할때.
        //2. 방문한 적이 없을때.
        if(computers[iCurNode][i] == 1 && iCurNode != i &&
          iVisited[i] == 0)
        {
            //"DFS" 또 방문해.
            DFS(i, computers, iNumComputers);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    //n은 컴퓨터의 갯수.
    for(int i=0; i<n; ++i)
    {
        if(!iVisited[i])
        {
            DFS(i, computers, n);
            answer++;
        }
    }
    
    return answer;
}