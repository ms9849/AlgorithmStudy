#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int iSum = 0;
    int iBinaryCount = 0;
    
    while(s != "1")
    {
        int iCount = 0;
        int iLength = s.length();
        string Temp = "";
        
        for(int i=0; i<iLength; ++i)
        {
            if(s[i] == '1')
                iCount++;
            else
                iSum++;
        }

        while(iCount >= 1)
        {
            Temp += to_string( iCount % 2 );
            iCount /= 2;
        }
        reverse(Temp.begin(), Temp.end());
        
        s = Temp;
        
        iBinaryCount++;
    }
    
    answer.push_back(iBinaryCount);
    answer.push_back(iSum);
    
    return answer;
}