#include <string>
#include <vector>

using namespace std;

int iMap[101][101] = {};
int iDp[101][101] = {};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto& iter : puddles)
    {
        iMap[iter[0]][iter[1]] = 1;
    }
    
    iDp[1][1] = 0;
    
    for(int i=1; i<=m; ++i)
    {
        if(iMap[i][1] != 1)
            iDp[i][1] = 1; 
        else
            break;
    }
    
    for(int i=1; i<=n; ++i)
    {
        if(iMap[1][i] != 1)
            iDp[1][i] = 1;
        else
            break; 
    }
    
    for(int i=2; i<=m; ++i)
    {
        for(int j=2; j<=n; ++j)
        {
            if(iMap[i][j] != 1)
                iDp[i][j] = (iDp[i-1][j] % 1000000007 + iDp[i][j-1] % 1000000007) % 1000000007;
            else 
                iDp[i][j] = 0;
        }
    }
    
    return iDp[m][n];
}