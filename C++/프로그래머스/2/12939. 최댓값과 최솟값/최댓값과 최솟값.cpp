#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
일단 다 숫자로 변환해서.. Sort 때리고, 다시 string으로 변환해야겠지?
*/
string solution(string s) 
{
    int iLength = s.length();
    vector<int> vecNums = {};
    string strTemp = {}, answer = {};
    
    for(int i=0; i<iLength; ++i)
    {
        if(s[i] != ' ')
            strTemp += s[i];
        else
        {
            int iTemp = stoi(strTemp);
            strTemp = "";
            vecNums.push_back(iTemp);
        }
    }
    
    int iTemp = stoi(strTemp);
    strTemp = "";
    vecNums.push_back(iTemp);
    
    sort(vecNums.begin(), vecNums.end());
    
    answer += to_string(vecNums[0]);
    answer += " ";
    answer += to_string(vecNums[vecNums.size()-1]);
    
    return answer;
}