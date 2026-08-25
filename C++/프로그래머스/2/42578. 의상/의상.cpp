#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string,int> CountParts= {};
    
    for(auto& iter: clothes)
    {
        //headgear ++
        CountParts[iter[1]]++;
    }
    
    for(auto& iter : CountParts)
    {
        if(answer == 0)
            answer = iter.second + 1;
        else
            answer *= (iter.second + 1);
    }
    
    answer--;
    
    return answer;
}