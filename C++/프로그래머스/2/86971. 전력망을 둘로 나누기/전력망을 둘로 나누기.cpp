#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int iAnswer = -1;
    int iLoseEdgeIdx = {};
    int iEdgeNums = wires.size(); 
    
    for(int i=0; i<iEdgeNums; ++i)
    {
        int iVisitedNodeCounter = {}; 
        int iVisited[101] = {};
        //i번째 인덱스의 간선은 쓸 수 없게 하기 위함.
        iLoseEdgeIdx = i;
    
        //BFS 로직.
        queue<int> q = {};
        q.push(1);
        iVisited[1] = 1;

        while(!q.empty())
        {
            int iCurNode = q.front();
            q.pop();


            int iIdx = 0;
            for(auto& iter : wires)
            {
                if(((iter[0] == iCurNode && iVisited[iter[1]] == 0))                         
                   && iIdx != iLoseEdgeIdx)
                {
                    iVisited[iter[1]] = 1;
                    q.push(iter[1]);
                }

                else if(((iter[1] == iCurNode && iVisited[iter[0]] == 0))                         
                   && iIdx != iLoseEdgeIdx)
                {
                    iVisited[iter[0]] = 1;
                    q.push(iter[0]);
                }

                iIdx++;
            }
        }

         
        int iCounter ={};
        for(int i=1; i<=n; ++i)
        {
            if(iVisited[i] == 1)
                iCounter++;
            else
                iCounter--;
        }
        if(iCounter < 0)
            iCounter *= -1; 
        
        if(iCounter < iAnswer || iAnswer == -1)
            iAnswer = iCounter;
    }
    
    return iAnswer;
}