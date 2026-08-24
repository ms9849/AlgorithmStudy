#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int iVisited[100001] = {};
vector<string> answer = {};
bool hasFinished = { false };

void DFS(const string& Current, const vector<vector<string>>& tickets, stack<string>& stAnswers, int iDepth)
{
    if(iDepth == tickets.size() && false == hasFinished)
    {
        while(!stAnswers.empty())
        {
            answer.push_back(stAnswers.top());
            stAnswers.pop();
        }
        
        hasFinished = true;
    }
    
    int iSize = tickets.size();
    vector<pair<string, int>> vecVisitable = {};
    for(int i=0; i<iSize; ++i)
    {
        if(tickets[i][0] == Current && iVisited[i] == 0)
            vecVisitable.push_back(make_pair(tickets[i][1], i));
    }
    
    sort(vecVisitable.begin(), vecVisitable.end());
    
    if(vecVisitable.size() == 0)
        return; 
    
    for(int i=0; i<vecVisitable.size(); ++i)
    {
        iVisited[vecVisitable[i].second] = 1;
        stAnswers.push(vecVisitable[i].first);
        
        DFS(vecVisitable[i].first, tickets, stAnswers, iDepth+1);
        
        if (hasFinished)
            return;
        
        iVisited[vecVisitable[i].second] = 0;
        stAnswers.pop();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    stack<string> stAnswers = {};
    string strStart = "ICN";
    
    DFS(strStart, tickets, stAnswers, 0);
    
    answer.push_back("ICN");
    reverse(answer.begin(), answer.end());
    return answer;
}