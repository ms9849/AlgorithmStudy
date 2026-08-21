#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> map = {};
    int iCount = 0;
    
    for(auto& iter : name)
    {
        map[iter] = yearning[iCount];
        iCount++;
    }
    
    int iRowSize = photo.size();
    
    for(int i=0; i<iRowSize; ++i)
    {
        int iColSize = photo[i].size(); 
        int iSum = 0;
        
        for(int j=0; j<iColSize; ++j)
        {
            iSum += map[ photo[i][j] ];    
        }
        
        answer.push_back(iSum);
    }
    
    
    return answer;
}