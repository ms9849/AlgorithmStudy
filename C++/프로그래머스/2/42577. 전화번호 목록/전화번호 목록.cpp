#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
100만개의 원소가 존재할 수 있으니까..
단순 2중 for문은 아님. 100억이 넘나? 아무튼..

map에 다 미리 등록해놓고, 2중 for문으로 체크하는건 되겠다.
100만번 * 20이니까. 
*/
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um = {};
    
    for(auto& iter : phone_book)
        um[iter]++;
    
    int iSize = phone_book.size();
    for(int i=0; i<iSize; ++i)
    {
        string strTemp = "";
        int iLength = phone_book[i].length();
        
        for(int j=0; j<iLength-1; ++j)
        {
            strTemp += phone_book[i][j];
        
            if(um.find(strTemp) != um.end())
                return false;
        }
    }
    
    return true;
}