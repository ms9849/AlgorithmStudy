#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int i=0; i<arr.size(); ++i)
    {
        int iCurNum = arr[i];
        int j = i+1;
        
        answer.push_back(iCurNum);
        
        while(iCurNum == arr[j] && j < arr.size())
        {
            j++;
        }
        i = j-1;
    }
    
    return answer;
}