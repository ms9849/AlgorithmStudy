#include <string>
#include <vector>
#include <set>

using namespace std;

/*
넣을때마다 Sort...는 안되겠지.
최대, 최소값을 보관하고 있는 두 개의 자료구조가 필..요하겠지.
map도 괜찮을까? set도 괜찮다곤 했던 것 같은데.
*/
vector<int> solution(vector<string> operations) {
    vector<int> answer = {};
    multiset<int> s = {};
    int iOperSize = operations.size();
    
    for(int i=0; i<iOperSize; ++i)
    {
        string strOper = operations[i];
        string strNum = {};
        
        switch(strOper[0])
        {
            case 'I':
                for(int i=2; i<strOper.size(); ++i)
                    strNum += strOper[i];
                s.insert(stoi(strNum));
                break;
            case 'D':
                
                if(strOper[2] == '-')
                    s.erase(*s.begin());   
                else
                    s.erase(*s.rbegin());
                
                break;
        }
    }
    
    if(!s.empty())
    {
        answer.push_back(*s.rbegin());
        answer.push_back(*s.begin());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}