#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int iMin = {};

    answer = arr;
    
    sort(arr.begin(), arr.end());
    iMin = arr[0];
    
    for(int i=0; i<answer.size(); ++i)
    {
        if(answer[i] == iMin)
            answer.erase(answer.begin() + i);
    }
    
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}