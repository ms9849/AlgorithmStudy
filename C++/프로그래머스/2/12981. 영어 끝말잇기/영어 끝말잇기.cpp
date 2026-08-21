#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {};
    unordered_map<string, int> map = {};
    
    int iLength = words.size();
    char cEnd = ' ';
    
    for(int i=0; i<iLength; ++i)
    {   
        // 이미 나왔거나, 끝말잇기가 성립 안한다면
        if(map[words[i]] != 0 || (cEnd != words[i][0]) && cEnd != ' ')
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        
        // 문자열 길이.
        cEnd = words[i][words[i].length()-1];
        map[words[i]]++;
    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}