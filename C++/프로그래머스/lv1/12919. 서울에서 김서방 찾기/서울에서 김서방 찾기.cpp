#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    int iIdx = 0;
    for(int i=0; i<seoul.size(); ++i)
    {
        if(seoul[i] == "Kim")
            iIdx = i;
    }
    
    answer = "김서방은 " + to_string(iIdx) + "에 있다";
    
    return answer;
}