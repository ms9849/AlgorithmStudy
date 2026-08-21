#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int iSize = commands.size();
    
    for(int i=0; i<iSize; ++i)
    {
        //어디서부터 어디까지 자를래?
        int iStart = commands[i][0] - 1;
        int iEnd = commands[i][1] - 1;
        //k번째 수.
        int iK = commands[i][2] - 1;
        
        //자른 숫자들을 저장하기 위한 벡터 컨테이너.
        vector<int> vecNums = {};
        for(int j=iStart; j<=iEnd; ++j)
        {
            vecNums.push_back(array[j]);
        }
        
        sort(vecNums.begin(), vecNums.end(), [](int ilhs, int irhs) -> bool         {
            return ilhs < irhs;
        });
        
        answer.push_back(vecNums[iK]);
    }
    
    
    return answer;
}