#include <string>
#include <vector>

using namespace std;
int iTarget = {};
int iCount = 0;
void Recursion(vector<int>& vecNumbers, int iCurNumber, int iDepth)
{
    if(iDepth == vecNumbers.size())
    {
        if(iTarget == iCurNumber)
        {
            iCount++;   
        }
        return;
    
    }
    
    Recursion(vecNumbers, iCurNumber + vecNumbers[iDepth], iDepth+1);

    iCurNumber - vecNumbers[iDepth];

    Recursion(vecNumbers, iCurNumber - vecNumbers[iDepth], iDepth+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    iTarget = target;
    
    Recursion(numbers, 0, 0);
    
    return iCount;
}