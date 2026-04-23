#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    int iCount = 0;
    while(budget >= 0 && iCount <= d.size())
    {
        budget -= d[iCount];
        
        iCount++;
    }
    
    answer = iCount-1;
    return answer;
}