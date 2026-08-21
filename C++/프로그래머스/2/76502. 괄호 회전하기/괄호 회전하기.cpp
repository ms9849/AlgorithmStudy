#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isFront(char c)
{
    return c == '(' || c == '[' || c == '{';
}
bool isPop(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool isPair(char top, char cur)
{
    return (top == '(' && cur == ')') || (top == '[' && cur == ']') || (top == '{' && cur == '}');
}

int solution(string s) {
    int answer = 0;
    int iLength = s.length();

    for (int i = 0; i < iLength; ++i)
    {
        bool isCorrect = { true };
        stack<char> st = {};

        for (int j = i; j < iLength; ++j)
        {
            if (st.empty() && isPop(s[j]))
                isCorrect = false;
            else if (!st.empty() && isPair(st.top(), s[j]))
                st.pop();
            else if (isFront(s[j]))
                st.push(s[j]);
            else
                isCorrect = false;
        }

        for (int k = 0; k < i; ++k)
        {
            if (st.empty() && isPop(s[k]))
                isCorrect = false;
            else if (!st.empty() && isPair(st.top(), s[k]))
                st.pop();
            else if (isFront(s[k]))
                st.push(s[k]);
            else
                isCorrect = false;
        }

        if (true == isCorrect && st.empty())
            answer++;
    }

    return answer;
}