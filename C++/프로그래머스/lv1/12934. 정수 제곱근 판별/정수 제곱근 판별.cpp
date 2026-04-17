#include <string>
#include <vector>
#include "math.h"

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long sqrtVal = sqrt(n);
    
    if(sqrtVal * sqrtVal != n)
    {
        return -1;
    }
    else
    {
        return (sqrtVal+1) * (sqrtVal+1);
    }
}