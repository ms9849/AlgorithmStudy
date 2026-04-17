#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int iSizeT = t.length();
    int iSizeP = p.length();
    
    for(int i = 0; i <= iSizeT - iSizeP; ++i)
    {
        string tmp  = {};
        for(int j = i; j < i + iSizeP; ++j)
        { 
            tmp += t[j];
        }
        
        if(tmp <= p)
            answer++;
    }
    
    return answer;
}