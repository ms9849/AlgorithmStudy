#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
그리디하게, 가장 높은 것들부터 묶어서 상자를 구성하면 될 것 같은디.
*/
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    priority_queue<int> pq = {};
    
    for(auto& iter : score)
        pq.push(iter);
    
    while(pq.size() >= m) 
    {
        int iMin = 999;
        for(int i=0; i<m; ++i)
        {
            if(pq.top() < iMin)
                iMin = pq.top();
            
            pq.pop();
        }
        
        answer += iMin * m;
    }
    
    
    
    return answer;
}