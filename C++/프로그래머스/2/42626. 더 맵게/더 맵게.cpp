#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq = {};
    
    for(auto& iter : scoville)
        pq.push(iter);
    
    while(pq.size() >= 2 && pq.top() < K)
    {
        int iFirst = pq.top();
        pq.pop();
        int iSecond = pq.top();
        pq.pop();
        
        int iMix = iFirst + iSecond * 2;
        pq.push(iMix);
        
        answer++;
    }
    
    if(pq.top() < K)
        return -1;
    
    return answer;
}