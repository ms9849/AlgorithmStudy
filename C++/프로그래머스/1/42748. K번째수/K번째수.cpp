#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int iCmdSize = commands.size();
    
    for(int i=0; i<iCmdSize; ++i)
    {
        int iFrom = commands[i][0];
        int iTo = commands[i][1];
        int iIdx = commands[i][2];
        
        vector<int> vecNums = {};
        
        for(int j=iFrom-1; j<iTo; ++j)
            vecNums.push_back(array[j]);
        
        sort(vecNums.begin(), vecNums.end());
        
        answer.push_back(vecNums[iIdx-1]);
    }
    
    return answer;
}