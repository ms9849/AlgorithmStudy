#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st = {};
    int iLength = s.length();
    
    for(int i=0; i<iLength; ++i)
    {
        if(st.empty() || (st.top() != s[i]))
            st.push(s[i]);
        else
            st.pop();
    }
    
    if(st.empty())
        return 1;
    else
        return 0;
}