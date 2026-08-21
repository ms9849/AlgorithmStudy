#include <string>
#include <vector>

using namespace std;

//2진수로 변환해서, 1의 갯수까지 세서 int로 반환
int Count_BinaryOne(int n)
{
    int iSum = 0;
    
    while(n>=1)
    {
        int iNum = n % 2;
        
        if(iNum == 1)
            iSum++;
        
        n /= 2;
    }
    
    return iSum;
}


int solution(int n) {
    int answer = 0;
    int iStart = n+1;
    int iCount = Count_BinaryOne(n);
    
    while(1)
    {
        if(iCount == Count_BinaryOne(iStart))
            break;
        
        iStart++;
    }
    
    return iStart;
}