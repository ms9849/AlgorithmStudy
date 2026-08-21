#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int iColSize = arr1.size();
    int iRowSize = arr1[0].size();
    
    answer.resize(iColSize);
    for(int i=0; i<iColSize; ++i)
    {
        answer[i].resize(iRowSize);
    }
    
    for(int i=0; i<iColSize; ++i)
    {
        for(int j=0; j<iRowSize; ++j)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
            
        }
    }
        
    
    return answer;
}