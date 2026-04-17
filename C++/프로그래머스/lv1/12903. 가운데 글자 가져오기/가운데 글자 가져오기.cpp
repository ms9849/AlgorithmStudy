#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int iIdx = s.length() / 2;
    
    if(s.length() % 2 == 0)
    {
        answer = (s[iIdx-1]);
        answer += + s[iIdx];
    }
    else
    {
        answer = s[iIdx];
    }
    
    
    
    return answer;
}