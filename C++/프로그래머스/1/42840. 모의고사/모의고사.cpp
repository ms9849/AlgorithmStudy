#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer = {};
    vector<int> vecFirst = { 1,2,3,4,5 };
    vector<int> vecSecond = { 2,1,2,3,2,4,2,5 };
    vector<int> vecThird = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> vecAnswers = {0,0,0};
    vector<int> vecSizes = { 5, 8, 10 };
    
    int iSize = answers.size();
    
    for(int i=0; i<iSize; ++i)
    {
        if(answers[i] == vecFirst[i % vecSizes[0]])
            vecAnswers[0]++;
        
        if(answers[i] == vecSecond[i % vecSizes[1]])
            vecAnswers[1]++;
        
        if(answers[i] == vecThird[i % vecSizes[2]])
            vecAnswers[2]++;
    }
    
    int iMax = -1;
    for(int i=0; i<3; ++i)
        if(vecAnswers[i] > iMax)
            iMax = vecAnswers[i];
    
    for(int i=0; i<3; ++i)
        if(vecAnswers[i] == iMax)
            answer.push_back(i+1);
    
    return answer;
}