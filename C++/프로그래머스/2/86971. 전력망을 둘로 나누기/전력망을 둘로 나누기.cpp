#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*
wires를 하나씩 없애가면서 dfs 2번 돌려서
전력망 갯수 확인하고
으어 끔찍해
*/

int iMap[101][101] = {};
int iVisited[101] = {};
int iNodeSize = {};

void DFS(int iCurNode, int& iDepth)
{
    for (int i = 1; i <= iNodeSize; ++i)
    {
        if (iVisited[i] == 0 && iMap[iCurNode][i] == 1)
        {
            iVisited[i] = 1;
            iDepth++;
            DFS(i, iDepth);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 99999999;
    int iSize = wires.size();
    iNodeSize = n;

    for (int i = 0; i < iSize; ++i)
    {
        memset(iVisited, 0, sizeof(iVisited));
        memset(iMap, 0, sizeof(iMap));
        //전력망 하나씩 끊어서 저장.
        for (int j = 0; j < iSize; ++j)
        {
            if (j != i)
            {
                iMap[wires[j][0]][wires[j][1]] = 1;
                iMap[wires[j][1]][wires[j][0]] = 1;
            }
        }


        vector<int> vecDepths = { 1,1 };
        int iIdx = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (0 == iVisited[i])
            {
                iVisited[i] = 1;
                DFS(i, vecDepths[iIdx++]);
            }

        }

        int iDiff = abs(vecDepths[0] - vecDepths[1]);

        if (iDiff < answer)
            answer = iDiff;
    }


    return answer;
}