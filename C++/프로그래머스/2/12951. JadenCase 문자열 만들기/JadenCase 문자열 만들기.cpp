#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int iSize = s.length();
    
    for(int i=0; i<iSize; ++i)
    {
        if(i == 0)
        {
            if(s[i] >= 'a' && s[i] <='z')
                answer += s[i] - 32;
            else
                answer += s[i];
        }
        else
        {
            if(s[i] >= 'a' && s[i] <= 'z' && s[i-1] == ' ')
                answer += s[i] - 32;
            else if(s[i] >= 'A' && s[i] <='Z' && s[i-1] != ' ')
                answer += s[i] + 32;
            else
                answer += s[i];
        }
    }
    
    return answer;
}