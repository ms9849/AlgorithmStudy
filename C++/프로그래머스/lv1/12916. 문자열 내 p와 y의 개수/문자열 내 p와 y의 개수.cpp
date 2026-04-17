#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int iCountP = { 0 };
    int iCountY = { 0 };

    for(int i=0; i<s.length(); ++i)
    {
        if(s[i] == 'p' || s[i] == 'P')
            iCountP++;
        
        if(s[i] == 'y' || s[i] == 'Y')
            iCountY++;
    }
    
    if(iCountP == iCountY)
        return true;
    
    else
        return false;
    
    return answer;
}