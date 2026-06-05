#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //증감 연산자를 앞에두면 어셈블리상에서 약간 빠르고 컴파일에러를 잘잡아주고..
    for(int i=0; i<commands.size(); ++i)
    {
        vector<int> vecTargets ={};
        
        for(int j=commands[i][0]-1; j<=commands[i][1]-1; ++j)
        {
            vecTargets.push_back(array[j]);
        }
        
        sort(vecTargets.begin(), vecTargets.end());
        answer.push_back(vecTargets[commands[i][2]-1]);
    }
    
    return answer;
}