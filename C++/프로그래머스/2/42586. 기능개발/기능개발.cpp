#include <string>
#include <vector>

using namespace std;

/*
그냥 시뮬레이션으로도 될 것 같은데..?
굳이 큐나 스택을 써야할 이유는 없어보인다.

아니네.. 벡터를 큐처럼 써야할 듯 싶다.
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(0 != progresses.size())
    {
        int iProgramCount = 0;
        int iSize = progresses.size();
        
        for(int i=0; i<iSize; ++i)
        {
            progresses[i] += speeds[i];
        }
        
        while(progresses.size() != 0 && progresses[0] >= 100)
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            iProgramCount++;
        }

        if(iProgramCount != 0)
            answer.push_back(iProgramCount);
    }
    
    return answer;
}