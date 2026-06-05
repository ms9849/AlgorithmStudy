#include <string>
#include <vector>

using namespace std;

int iVisited[201] = {};
vector<vector<int>> vecMaps ={};

void Recursion(int iCurNode, int iMax)
{
    iVisited[iCurNode] = 1;
    
    for(int i=0; i<=iMax; ++i)
    {
        if(vecMaps[iCurNode][i] == 1 &&
          iVisited[i] == 0 &&
          i != iCurNode)
        {
            Recursion(i, iMax);
        }
    }

    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int iAnswer = 0;
    vecMaps = computers;
    
    for(int i=0; i<n; ++i)
    {
        if(iVisited[i] == 0)
        {
            Recursion(i, n-1);
            iAnswer++;
        }
    }
    return iAnswer;
}