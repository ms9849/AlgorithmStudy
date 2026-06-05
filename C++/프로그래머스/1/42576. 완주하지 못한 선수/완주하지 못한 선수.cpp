#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> mapInfos ={};
    string answer = {}; 
    
    for(auto& iter : participant)
    {
        mapInfos[iter]++;
    }
    
    for(auto& iter : completion)
    {
        mapInfos[iter]--;
    }
    
    for(auto& iter : mapInfos)
    {
        if(iter.second != 0)
        {
            answer = iter.first;
        }
    }
    
    return answer;
}