#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    int i = 1;
    while(1)
    {
        if(n % i == 1)
            return i;
        
        i++;
    }
    
    return answer;
}