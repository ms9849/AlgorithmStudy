#include <string>
#include <vector>

using namespace std;

/*
1024 * 1024 -> 1,000,000번이라 시간 복잡도는 괜찮다.
숫자의 크기도 적절함. 
타겟 넘버의 크기도 적당함. 
*/


void DFS(const vector<int>& numbers, int target, int current, int idx, int& answer)
{   
    if(idx == numbers.size())
    {
        if(current == target)
            answer+=1;
        return;
    }
    
    DFS(numbers, target, current + numbers[idx], idx+1, answer);
    DFS(numbers, target, current - numbers[idx], idx+1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, 0, 0, answer);
    
    return answer;
}