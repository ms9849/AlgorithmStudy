#include <string>
#include <vector>
#include <set>
using namespace std;
//999 9999

set<int> s= {};

bool IsPrime(int n)
{
    if(n <= 1)
        return false;
    
    for(int i=2; i<n; ++i)
    {
        //소수니까.. 1과 자기자신을 제외한 약수가 없어야지.
        if(n%i == 0)
            return false;
    }
    
    return true;
}

int iVisited[8] = {};

void DFS(string CurNum, const string& numbers)
{
    if(CurNum.length() != 0)
    {
        if(IsPrime(stoi(CurNum)))
            s.insert(stoi(CurNum));
    }
    
    for(int i=0; i<numbers.size(); ++i)
    {
        if(iVisited[i] != 1)
        {
            iVisited[i] = 1;
            DFS(CurNum + numbers[i], numbers);
            iVisited[i] = 0;
        }
    }
}

int solution(string numbers) {
    DFS("" ,numbers);
    
    return s.size();
}