#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int iIdx = 0;
    
    for(int i=0; i<s.length(); ++i)
    {
        if(s[i] == ' ')
        {         
            answer += s[i];
            iIdx = 0;
            continue;
        }
        
        if(iIdx % 2 == 1)
            answer += tolower(s[i]);
        else
            answer += toupper(s[i]);
        
        iIdx++;
    }
    return answer;
}