#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> vecDirs = {
    {1,0},
    {1,1}
};

int iDp[501][501] = {};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    iDp[0][0] = triangle[0][0];
    
    if(triangle.size() >= 1)
    {
        iDp[1][0] = iDp[0][0] + triangle[1][0];
        iDp[1][1] = iDp[0][0] + triangle[1][1];
    }

    
    for(int i=2; i<triangle.size(); ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if(j == 0)
            {
                iDp[i][j] = iDp[i-1][j] + triangle[i][j];
            }
            else if(j == i)
            {
                iDp[i][j] = iDp[i-1][j-1] + triangle[i][j];
            }
            else
            {    
                iDp[i][j] = max(iDp[i-1][j-1], iDp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    for(int i=0; i<triangle.size(); ++i)
    {
        answer = max(answer, iDp[triangle.size()-1][i]);
    }
    
    return answer;
}