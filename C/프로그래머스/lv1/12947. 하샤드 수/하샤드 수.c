#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    
    int iValue = x;
    int iSum = 0;
    while(x != 0)
    {
        iSum += x % 10;
        x /= 10;
    }
    
    answer = (iValue % iSum == 0);
    
    return answer;
}