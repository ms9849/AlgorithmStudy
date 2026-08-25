#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
pq는 불가능. 시뮬레이션이 필요하니까, 내림차순으로 정렬된 vector 하나와
실제 queue가 필요함.
*/
int solution(vector<int> priorities, int location) {
    int answer = 0;
    // (우선순위, 원본 인덱스)
    queue<pair<int,int>> q = {};
    
    for(int i=0; i<priorities.size(); ++i)
    {
        // 원본 위치를 기억하게 하면서 삽입.
        q.push(make_pair(priorities[i],i));
    }
    
    sort(priorities.begin(), priorities.end(), [](int lhs, int rhs)->bool {
        return lhs > rhs;
    });
    
    int iCount = 1;
    while(!q.empty())
    {
        int iPrior = priorities[0];
        
        while(1)
        {
            pair<int,int> p = q.front();
            
            if(p.first == iPrior)
            {              
                priorities.erase(priorities.begin());
                q.pop();
                if(p.second == location)
                    return iCount;
                iCount++;
                break;
            }
            else
            {
                q.push(p);   
                q.pop();
            }
        }
    }
    
    
    
    return answer;
}