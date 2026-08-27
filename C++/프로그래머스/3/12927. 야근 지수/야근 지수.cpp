#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
works가 2만이니까... 최대값으로 10억까지 나올 수 있음.
long long을 써야..하긴 하지.

1. 큰 수부터 줄여야함 -> Pq로 push & pop 할까?
*/
long long solution(int n, vector<int> works) {
    long long answer = 0;
    int iSize = works.size();
    priority_queue<int, vector<int>, less<int>> pq = {};
    
    for(int i=0; i<iSize; ++i)
        pq.push(works[i]);
    
    while(n != 0 && pq.top() > 0)
    {
        int iNum = pq.top();
        pq.pop();

        pq.push(--iNum);
        n--;
    }
    
    while(!pq.empty())
    {
        int iNum = pq.top();
        pq.pop();
        
        answer += iNum * iNum;
    }
    
    return answer;
}