#include <string>
#include <iostream>
#include <stack>
using namespace std;

/*
스택에 ( 는 넣고, ) 만나면 pop.

1. 만약 empty일때 pop 하려고 하거나,
2. 연산이 끝난 후 스택이 비어있지 않다면 올바르지 않은 괄호.
*/

bool solution(string s)
{
    bool answer = true;
    int iLength = s.length();
    stack<char> st;
    
    for(int i=0; i<iLength; ++i)
    {
        if(s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if(!st.empty())
                st.pop();
            else
                return false;
        }
    }
    
    if(!st.empty())
        return false;
    
    return true;  
}