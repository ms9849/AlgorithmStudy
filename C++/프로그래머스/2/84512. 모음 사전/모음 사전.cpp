#include <string>
#include <vector>

using namespace std;

string strTarget = {};
vector<char> vecMaps = { 'A', 'E', 'I', 'O', 'U'};
int iAnswer = 0;
int iCount = 0;
void DFS(string strCur)
{
    iCount++;
    
    if(strCur == strTarget)
        iAnswer = iCount;
    
    if(strCur.length() >= 5)
        return;
    
    for(int i=0; i<5; ++i)
    {
        DFS(strCur + vecMaps[i]);
    }
}

int solution(string word) {
    int answer = 0;
    strTarget = word;
    
    DFS("");
    return iAnswer-1;
}