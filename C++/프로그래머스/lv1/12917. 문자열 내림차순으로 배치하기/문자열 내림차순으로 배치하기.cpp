#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v ={};
    
    for(int i=0; i<s.length(); ++i)
        v.push_back(s[i]);
    
    sort(v.begin(), v.end(), [](char lhs, char rhs)->bool {
        return lhs > rhs;
    });
    
    for(int i=0; i<v.size(); ++i)
        answer += v[i];
    
    return answer;
}