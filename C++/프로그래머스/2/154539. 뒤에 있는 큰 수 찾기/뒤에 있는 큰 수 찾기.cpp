#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
단순 2중for문은 아닐 것이다.
stack을 이용해서 차차 담아가면서 풀어낼 수 있을 것 같음.
*/

vector<int> solution(vector<int> numbers) {
    vector<int> answer = {};
    
    int iAnswer[1000001] = {};
    //idx, number
    stack<pair<int,int>> st = {};
    int iSize = numbers.size();
    
    for(int i=0; i<iSize; ++i)
    {
        while(!st.empty() && st.top().second < numbers[i])
        {
            pair<int,int> pTemp = st.top();
            iAnswer[pTemp.first] = numbers[i];
            st.pop();
        }
        
        st.push(make_pair(i, numbers[i]));
    }
    
    for(int i=0; i<iSize; ++i)
    {
        if(iAnswer[i] == 0)
            answer.push_back(-1);
        else
            answer.push_back(iAnswer[i]);
    }
    
    return answer;
}