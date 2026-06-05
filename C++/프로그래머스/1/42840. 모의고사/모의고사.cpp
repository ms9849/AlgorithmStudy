#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //1번 수포자
    vector<int> vecFirst = { 1,2,3,4,5};   
    int iAnswerFirst = {};
    //2번 수포자
    vector<int> vecSecond = {2,1,2,3,2,4,2,5};
        int iAnswerSecond = {};
    //3번 수포자
    vector<int> vecThird = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
        int iAnswerThird = {};
    
    for(int i=0; i<answers.size(); ++i)
    {
        if(answers[i] == vecFirst[i % vecFirst.size()])
        {
            iAnswerFirst++;
        }
        if(answers[i] == vecSecond[i % vecSecond.size()])
        {
            iAnswerSecond++;
        }
        
        if(answers[i] == vecThird[i % vecThird.size()])
        {
            iAnswerThird++;
        }
    }
    
    int iMax = iAnswerFirst > iAnswerSecond ? iAnswerFirst : iAnswerSecond;
    iMax = iMax > iAnswerThird ? iMax : iAnswerThird;
    
    if(iMax == iAnswerFirst)
        answer.push_back(1);    
    if(iMax == iAnswerSecond)
        answer.push_back(2);    
    if(iMax == iAnswerThird)
        answer.push_back(3);
    
    return answer;
}