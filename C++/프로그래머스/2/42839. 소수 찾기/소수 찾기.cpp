#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
최종 숫자에 붙이냐, 붙이지 않냐 2개의 상황만이 존재한다.
소수인지 체크해야하고. -> 에라토스테네스의 체는 메모리 문제로 불가능할 것.
1024개의 소수니까.. 그냥 브루트포스로 해결 가능
*/
int iVisited[10] = {};
vector<string> vecNumbers = {};
set<int> setNumbers = {};

void Recursion(int iMaxDepth, string strCurrent)
{
    if(strCurrent.size() == iMaxDepth)
    {
        bool isMinor = { true };
        int iNumber = stoi(strCurrent);
        
        for(int i=2; i<iNumber; ++i)
        {
            if(iNumber % i == 0)
            {
                isMinor = false;
                break;
            }
        }
        
        if(true == isMinor && iNumber > 1)
            setNumbers.emplace(iNumber);
        
        return;
    }
    
    
    string strOrigin = strCurrent;
    for(int i=0; i<vecNumbers.size(); ++i)
    {
        if(iVisited[i] == 0)
        {
            iVisited[i] = 1;
            Recursion(iMaxDepth, strOrigin + vecNumbers[i]);
            iVisited[i] = 0;
        }
    }
    
}

int solution(string strNumbers) {

    for(int i=0; i<strNumbers.size(); ++i)
    {
        vecNumbers.push_back(strNumbers.substr(i, 1));
    }
    
    for(int i=1; i<=vecNumbers.size(); ++i)
    {
        for(int i=0; i<10; ++i)
            iVisited[i] = 0;
        
        Recursion(i, "");
    }
    
    
    return setNumbers.size();
}